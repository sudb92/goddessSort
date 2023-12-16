{
    gBenchmark->Start("timestamp");
    gSystem->Load("../libGRETINA.so");
    gSystem->Load("../libS800.so");

    gBenchmark->Show("timestamp");
}