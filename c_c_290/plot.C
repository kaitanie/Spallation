{
ifstream file("C-C-290-30deg.data");
Double_t E, CX;

TGraph *g1 = new TGraph();
Int_t i = 0;
while(1) {
	file >> E >> CX;
	if(!file.good()) break;
	cout <<"E = " << E << "   CX = " << CX << endl;
	g1->SetPoint(i, E, CX);
	i++;
}

file.close();
gStyle->SetMarkerStyle(2);
g1->Draw("aP");
}
