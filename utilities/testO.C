{
    //Tip: Feed a small input for quick sampling
    TFile *f = new TFile("../output/001_orruba_raw.root");
    TTree *tt = (TTree*)(f->Get("dataRaw"));
    gStyle->SetHistFillStyle(1001);
    gStyle->SetHistFillColor(kGreen-3);
//    gStyle->SetOptLogy(kTRUE);
    double lowlim = 1.0; // set the least number to be present in each adc for there to be an 'event' worthy of multiplicity

    TCanvas *c = new TCanvas();
    c->Divide(6,5);
    int i=0;

    c->cd(++i);    tt->Draw("dQQQ5RingMul_dE:dQQQ5RingChannel_dE",Form("dQQQ5RingADC_dE>%f",lowlim),"");
    c->cd(++i);    tt->Draw("dQQQ5DetRingMul_dE:dQQQ5RingChannel_dE",Form("dQQQ5RingADC_dE>%f",lowlim),"");
    c->cd(++i);    tt->Draw("dQQQ5SectorMul_dE:dQQQ5SectorChannel_dE",Form("dQQQ5SectorADC_dE>%f",lowlim),"");
    c->cd(++i);    tt->Draw("dQQQ5DetSectorMul_dE:dQQQ5SectorChannel_dE",Form("dQQQ5SectorADC_dE>%f",lowlim),"");

    c->cd(++i);    tt->Draw("dQQQ5RingMul_E:dQQQ5RingChannel_E",Form("dQQQ5RingADC_E>%f",lowlim),"");
    c->cd(++i);    tt->Draw("dQQQ5DetRingMul_E:dQQQ5RingChannel_E",Form("dQQQ5RingADC_E>%f",lowlim),"");
    c->cd(++i);    tt->Draw("dQQQ5SectorMul_E:dQQQ5SectorChannel_E",Form("dQQQ5SectorADC_E>%f",lowlim),"");
    c->cd(++i);    tt->Draw("dQQQ5DetSectorMul_E:dQQQ5SectorChannel_E",Form("dQQQ5SectorADC_E>%f",lowlim),"");

    c->cd(++i);    tt->Draw("uQQQ5RingMul:uQQQ5RingChannel",Form("uQQQ5RingADC>%f",lowlim),"");
    c->cd(++i);    tt->Draw("uQQQ5DetRingMul:uQQQ5RingChannel",Form("uQQQ5RingADC>%f",lowlim),"");
    c->cd(++i);    tt->Draw("uQQQ5SectorMul:uQQQ5SectorChannel",Form("uQQQ5SectorADC>%f",lowlim),"");
    c->cd(++i);    tt->Draw("uQQQ5DetSectorMul:uQQQ5SectorChannel",Form("uQQQ5SectorADC>%f",lowlim),"");

    c->cd(++i);    tt->Draw("BB10Mul:BB10Channel",Form("BB10ADC>%f",lowlim));
    c->cd(++i);    tt->Draw("BB10DetMul:BB10Channel",Form("BB10ADC>%f",lowlim));

    c->cd(++i);    tt->Draw("dSX3LeftMul:dSX3LeftChannel",Form("dSX3LeftADC>%f",lowlim));
    c->cd(++i);    tt->Draw("dSX3DetLeftMul:dSX3LeftChannel",Form("dSX3LeftADC>%f",lowlim));

    c->cd(++i);    tt->Draw("dSX3RightMul:dSX3RightChannel",Form("dSX3RightADC>%f",lowlim));
    c->cd(++i);    tt->Draw("dSX3DetRightMul:dSX3RightChannel",Form("dSX3RightADC>%f",lowlim));

    c->cd(++i);    tt->Draw("dSX3BackMul:dSX3BackChannel",Form("dSX3BackADC>%f",lowlim));
    c->cd(++i);    tt->Draw("dSX3DetBackMul:dSX3BackChannel",Form("dSX3BackADC>%f",lowlim));

    c->cd(++i);    tt->Draw("uSX3LeftMul:uSX3LeftChannel",Form("uSX3LeftADC>%f",lowlim));
    c->cd(++i);    tt->Draw("uSX3DetLeftMul:uSX3LeftChannel",Form("uSX3LeftADC>%f",lowlim));

    c->cd(++i);    tt->Draw("uSX3RightMul:uSX3RightChannel",Form("uSX3RightADC>%f",lowlim));
    c->cd(++i);    tt->Draw("uSX3DetRightMul:uSX3RightChannel",Form("uSX3RightADC>%f",lowlim));

    c->cd(++i);    tt->Draw("uSX3BackMul:uSX3BackChannel",Form("uSX3BackADC>%f",lowlim));
    c->cd(++i);    tt->Draw("uSX3DetBackMul:uSX3BackChannel",Form("uSX3BackADC>%f",lowlim));

    c->cd(++i);    tt->Draw("0.5*(uSX3LeftADC+uSX3RightADC)","uSX3LeftADC>1 && uSX3RightADC>1");
    c->cd(++i);    tt->Draw("0.5*(dSX3LeftADC+dSX3RightADC)","dSX3LeftADC>1 && dSX3RightADC>1");
    c->cd(++i);    tt->Draw("uSX3BackChannel","");


    c->UseCurrentStyle();
    c->Modified();
    c->Update();

    i=0;
    TCanvas *c2 = new TCanvas();
    c2->Divide(2,1);
    c2->cd(++i);    tt->Draw("BB10ADC:dSX3BackADC","BB10ADC!=0 && dSX3BackADC!=0","col2z");
    c2->cd(++i);    tt->Draw("dQQQ5SectorADC_dE:dQQQ5SectorADC_E","dQQQ5SectorADC_dE!=0 && dQQQ5SectorADC_E!=0","col2z");
    c2->Modified();
    c2->Update();

    f->Close();
}
