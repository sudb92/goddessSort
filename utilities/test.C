{
    gBenchmark->Start("timestamp");
    gSystem->Load("../libGRETINA.so");
    constexpr int limit=100;

    TFile* f = new TFile("../output/123_gretina.root");
    TTree* gt = (TTree*)(f->Get("teb"));
    Long64_t nentries = gt->GetEntries();

    gt->SetEstimate(-1);

    Int_t ng = gt->Draw("Entry$:xtals.timestamp[0]",Form("Entry$<%d",limit),"goff");
//    Int_t ng = gt->Draw("Entry$:xtals.timestamp[0]","","goff");

    Double_t* tgret = gt->GetVal(1);

/*   std::vector<double> ones, twos;
   ones.resize(ng); twos.resize(no);
   std::fill(ones.begin(),ones.end(),1.0);
   std::fill(twos.begin(),twos.end(),2.0);
   std::vector<double> tgretv, torrv;
   tgretv.assign(tgret,tgret+ng);
   torrv.assign(torr,torr+no);*/
    std::cout << ng << " " << limit << std::endl;

    Double_t ones[limit] = {[0 ... limit-1]=1.0};
    Double_t zeros[limit] = {[0 ... limit-1]=0.0};
    Double_t ebars[limit] = {[0 ... limit-1]=1000.0};

/*    for(int i=0; i< limit; i++){
        std::cout << std::setprecision(20) << tgret[i] << std::endl;
    }*/

    TGraph *g1 = new TGraph(limit,tgret,ones);
    //TGraph *g2 = new TGraphErrors(limit,torr,ones,ebars,zeros);
    g1->SetMarkerColor(kRed);
    g1->SetTitle("Gretina Timestamps");
    g1->SetMarkerStyle(kCircle);

  //  g2->SetTitle("ORRUBA Timestamps");
  //  g2->SetMarkerStyle(kFullDotMedium);

    TCanvas *c = new TCanvas();
    g1->Draw("ap");
    //g2->Draw("p");
    //t->Print();
    c->BuildLegend();
    c->Update();
    f->Close();
    gBenchmark->Show("timestamp");

}
