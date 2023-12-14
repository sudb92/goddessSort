/*  Attempts to plot all events in a (theta,phi) plane
    Quads i.e. crystal/4 at (6, 9, 12, 14, 17, 19, 21, 22, 24, 25, 26, 29) */

R__LOAD_LIBRARY(../libGRETINA.so)
void testDF() {
//    gStyle->SetOptStat(0);
    gStyle->SetTitle("");
    gStyle->SetCanvasPreferGL(1);
    int limit = 12;
    ROOT::RDataFrame df("mergtree","../output/123_combined.root");
    std::vector<std::string> colNames = df.GetColumnNames();
    for(auto thing : colNames)
        std::cout << thing << std::endl;

    auto h2model = ROOT::RDF::TH2DModel("polar-vs-etot","polar versus etot",360.,-180.,180.,180.,0.,180.);
    auto df2 = df.Define("yy","(xtals_ylab[0]<0)*(xtals_ylab[0]-7.061)+(xtals_ylab[0]>=0)*(xtals_ylab[0]+12.37)")
                 .Define("xx","xtals_xlab[0]")
                 .Define("zz","xtals_zlab[0]")
                 .Define("theta","atan2(yy,xx)*180./TMath::Pi()")
                 .Define("phi","atan2(pow(yy*yy+xx*xx,0.5),zz)*180./TMath::Pi()");

    int list[12] = {6,9,12,14,17,19,    21,22,24,25,26,29};
    int color[12] = {kRed,    kGreen,  kBlue,  kCyan,  kYellow+1,  kBlack,
                     kBlue+3, kGray+1,   kPink+2,  kTeal,  kMagenta,  kOrange};
    int i = 0;

//    std::array<std::unique_ptr<TH2F>,12> h2;
    TH2F* h2[12];
    for(int i=0;i<limit;i++) {
        auto slice = df2.Filter(Form("xtals_quadNum[0]==%d",i+1));
//        h2[i] = std::make_unique<TH2F>(slice.Histo2D(h2model,"theta","phi")->Clone());
        h2[i] = (TH2F*)(slice.Histo2D(h2model,"theta","phi")->Clone());
        std::cout << i << " done." << std::endl;
    }

//    std::unique_ptr<TCanvas> c(new TCanvas());
    TCanvas *c=new TCanvas();
    h2[0]->SetTitle("run 123");
    TFile *fout = new TFile("output_plotGeom.root","recreate");
    for(int i=0;i<limit;i++) {
        h2[i]->SetMarkerColorAlpha(color[i],0.1);
        h2[i]->Draw("same");
        gDirectory->WriteObject(h2[i],Form("h%d",i));
        //break;
    }

    fout->Close();
}
