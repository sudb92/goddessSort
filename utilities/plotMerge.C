{
    gStyle->SetOptStat(0);
    gStyle->SetTitle("");
    gSystem->Load("../libGRETINA.so");

    TFile *f = new TFile("../output/123_combined_fast.root");
    TTree *gtree = (TTree*)(f->Get("mergtree"));
    //gtree->Print();
    gtree->Draw("xtals_cc>>htemp(10000,0,10000)","","goff");
    gtree->Draw("(GRETINATimeStamp-timeStamp)>>dt(800)","foundGRETINA","goff");
    TH1F* h1 = (TH1F*)(gDirectory->Get("htemp"));
    TH1F* h2 = (TH1F*)(gDirectory->Get("dt"));
    h1->SetLineColor(kRed);
    h2->SetLineColor(kBlack);

    TCanvas *c = new TCanvas();
    c->Divide(2,2);
    auto c1=c->cd(1);
    h1->Draw();
    c1->SetLogy();
    auto c2=c->cd(2);
    h2->Draw();
    c->Modified();
    c->Update();
    c->BuildLegend();
}
