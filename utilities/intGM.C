{
    //Tip: Feed a small input for quick sampling
    TFile *f = new TFile("../output/123_orruba_raw.root");
    TTree *tt = (TTree*)(f->Get("dataRaw"));
    gStyle->SetHistFillStyle(1001);
    gStyle->SetCanvasPreferGL(1);
//    gStyle->SetOptLogy(kTRUE);
    double lowlim = 1.0; // set the least number to be present in each adc for there to be an 'event' worthy of multiplicity

    TCanvas *c = new TCanvas();
    c->Divide(4,4);
    int cid=0;
    int backch[4]={160,159,158,157};
    int minch[4]={217,219,221,223};

    TH2F *h[16];
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++) {
        int maxch=minch[i]+1;

        TString cut = Form("uSX3RightADC>0 && uSX3RightADC>0 && uSX3BackADC>0 && uSX3BackChannel==%d && uSX3LeftChannel>=%d && uSX3LeftChannel<=%d && uSX3RightChannel>=%d && uSX3RightChannel<=%d",backch[j],minch[i],maxch,minch[i],maxch);

        c->cd(++cid);    tt->Draw(Form("(uSX3RightADC+uSX3LeftADC):uSX3BackADC>>h%d(800,0,4096,800,0,4096)",cid),cut,"goff"); // uSX3RightChannel<=224
        h[cid-1] = (TH2F*)(gDirectory->Get(Form("h%d",cid)))->Clone();
        h[cid-1]->SetTitle(Form("f%d:b%d",minch[i],backch[j]));
/*        c->cd(++cid);    tt->Draw("uSX3RightADC:uSX3LeftADC",cut); // uSX3RightChannel<=224
        c->cd(++cid);    tt->Draw("(uSX3RightADC-uSX3LeftADC)/(uSX3RightADC+uSX3LeftADC)",cut); // uSX3RightChannel<=224
        c->cd(++cid);    tt->Draw("(uSX3RightADC+uSX3LeftADC):((uSX3RightADC-uSX3LeftADC)/(uSX3RightADC+uSX3LeftADC))",cut); // uSX3RightChannel<=224
*/
       h[cid-1]->SetMarkerStyle(kOpenCircle);
       h[cid-1]->SetMarkerColorAlpha(kBlack,0.5);
       h[cid-1]->DrawCopy("PMC");
//       h[cid-1]->Draw("PCOL");
    }
    c->UseCurrentStyle();
    c->Modified();
    c->Update();

    f->Close();
}
