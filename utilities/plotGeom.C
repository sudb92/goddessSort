/*
    Attempts to plot all events in a (theta,phi) plane
    Quads i.e. crystal/4 at (6, 9, 12, 14, 17, 19, 21, 22, 24, 25, 26, 29)

*/
R__LOAD_LIBRARY(../libGRETINA.so)
void plotGeom()
{
//    gStyle->SetOptStat(0);
    gStyle->SetTitle("");
    gStyle->SetCanvasPreferGL(1);
    int limit = 12;
    TFile *f = new TFile("../output/123_combined.root");
    TTree *gtree = (TTree*)(f->Get("mergtree"));

    gtree->Print();
    gtree->SetAlias("yy","(xtals_ylab<0)*(xtals_ylab-7.061)+(xtals_ylab>=0)*(xtals_ylab+12.37)");
//    gtree->SetAlias("yy","xtals_ylab");
    gtree->SetAlias("xx","xtals_xlab");
    gtree->SetAlias("zz","xtals_zlab");


    gtree->SetAlias("theta","TMath::ATan2(yy,xx)*180./TMath::Pi()");
    gtree->SetAlias("phi","TMath::ATan2(TMath::Power(yy*yy+xx*xx,0.5),zz)*180./TMath::Pi()");

    int list[12] = {6,9,12,14,17,19,    21,22,24,25,26,29};

    int color[12] = {kRed,    kGreen,  kBlue,  kCyan,  kYellow+1,  kBlack,
                     kBlue+3, kGray+1,   kPink+2,  kTeal,  kMagenta,  kOrange};

    int i = 0;
    gtree->SetCacheSize(300'000'000LL);

    for(int i=0;i<limit;i++) {
        gtree->Draw(Form("phi:theta>>h%d(360.,-180.,180.,180.,0.,180.)",i),Form("xtals_quadNum==%d",i+1),"goff");
        std::cout << i << " done." << std::endl;
    }

    TH2F* h[12];
    for(int i=0;i<limit;i++) {
        h[i] = (TH2F*)(gDirectory->Get(Form("h%d",i))->Clone());
        h[i]->SetMarkerColorAlpha(color[i],0.1);
    }
    h[0]->SetTitle("run 123");
    TFile *fout = new TFile("output_plotGeom.root","recreate");
    for(int i=0;i<limit;i++) {
        gDirectory->WriteObject(h[i],Form("h%d",i));
    }
    TCanvas *c=new TCanvas();
//    c->Divide(4,4);
//    h[0]->Draw();
    for(int i=0;i<limit;i++) {
//        auto cc= c->cd(i+1);
//        h[i]->Draw("cont1z sph");
        h[i]->Draw("same");
//        cc->Modified();
//        cc->Update();
//        break;
    }
    fout->Close();


}
