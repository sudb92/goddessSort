{
    gStyle->SetOptStat(0);
    gStyle->SetTitle("");
    gSystem->Load("../libGRETINA.so");

    TFile *f = new TFile("../output/123_gretina.root");
    TTree *gtree = (TTree*)(f->Get("teb"));
    gtree->Print();
    gtree->Draw("xtals.cc>>htemp(10000,0,10000)","","goff");
    gtree->Draw("Sum$(xtals.cc)>>htemp2(10000,0,10000)","","goff");
    TH1F* h1 = (TH1F*)(gDirectory->Get("htemp"));
    TH1F* h2 = (TH1F*)(gDirectory->Get("htemp2"));
    h1->SetLineColor(kRed);
    h2->SetLineColor(kBlack);

    TCanvas *c = new TCanvas();
    c->cd();
    h1->Draw();
    h2->Draw("SAME");
    c->Modified();
    c->Update();
    c->SetLogy();
    c->BuildLegend();
}
