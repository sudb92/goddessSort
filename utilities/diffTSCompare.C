{
    gStyle->SetCanvasPreferGL(1);
    gStyle->SetOptStat(0);
    gStyle->SetTitle("");
    gSystem->Load("../libGRETINA.so");

    TFile *f = new TFile("../output/123_combined_fast.root");
    TTree *gtree = (TTree*)(f->Get("mergtree"));
    TFile *f2 = new TFile("../output/123_combined.root");
    TTree *gtree_old = (TTree*)(f2->Get("mergtree"));

    gtree->Print();
    gtree_old->Print();
    gtree->Draw("(GRETINATimeStamp - timeStamp)>>t_new(1000,-1000,1000)","foundGRETINA==1","goff");
    gtree_old->Draw("(GRETINATimeStamp - timeStamp)>>t_old(1000,-1000,1000)","foundGRETINA==1","goff");

    TH1F* hn = (TH1F*)(gDirectory->Get("t_new"));
    TH1F* ho = (TH1F*)(gDirectory->Get("t_old"));
    hn->SetLineColor(kRed);
    ho->SetLineColor(kBlack);
    hn->SetTitle("fast");
    ho->SetTitle("comp");
//    hn->Add(ho,-1);

    TCanvas *c = new TCanvas();
    c->ToggleEditor();
    c->ToggleEventStatus();
    c->cd();
    hn->Draw();
    ho->Draw("SAME");


    c->Modified();
    c->Update();
    c->SetLogy();
    c->BuildLegend();
}
