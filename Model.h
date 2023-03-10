#ifndef _MODEL_H
#define _MODEL_H
#include"PhysicalConstant.h"
#include<string>
#include<direct.h>
#include"Object.h"
#include"Field.h"
#include<iostream>

using namespace std;
enum INTEG{
	D_XY = 0,
	D_X,
	D_Y
};

class FazzyModel {
protected:
	Field * mField;

public:
	FazzyModel(Field *field) {
		mField = field;
	};
	virtual string mkdir(string root) = 0;
	virtual double calcEPS(const double&, const double&, enum INTEG = D_XY) = 0;
	virtual double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) = 0;
	
	virtual bool update(int) = 0;
	virtual void Initialize() = 0;
	virtual void InitializeLambda(double a) {
	}
};

class FazzySlabModel :public FazzyModel{
	const double ep1, ep2;
	const int width1, width2;
public:
	FazzySlabModel(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	//JIADE
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	//JIADE
	bool update(int){
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};
class Fazzy_amber :public FazzyModel {
	const double ep1, ep2;
	const int width1, width2;
public:
	Fazzy_amber(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	//JIADE
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	//JIADE
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};


class Fazzy_amber_meso :public FazzyModel {
	double ep;
	double ep1;
	double ep2;
	double r;
	double r1;
	double r2;
	double r3;
public:
	Fazzy_amber_meso(Field* f);
	string mkdir(string root);
	virtual void InitializeLambda(double a) {
		this->r = mField->nanoToCell(a);
		cout << "r=" + to_s((int)mField->cellToNano(r)) << endl;
	}

	double calcEPS(const double& x, const double& y, enum INTEG f);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	bool update(int a) {

		return false;
	}
	void Initialize()
	{
	}
};
class Fazzy_amber_noise :public FazzyModel {
	double ep;
	double ep1;
	double ep2;
	double r;
	double r1;
	double r2;
	double r3;
public:
	Fazzy_amber_noise(Field* f);
	string mkdir(string root);
	virtual void InitializeLambda(double a) {
		this->r = mField->nanoToCell(a);
		cout << "r=" + to_s((int)mField->cellToNano(r)) << endl;
	}

	double calcEPS(const double& x, const double& y, enum INTEG f);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	bool update(int a) {

		return false;
	}
	void Initialize()
	{
	}
};
class Fazzy_hairslab :public FazzyModel {
	const double ep1, ep2;
	const int width1, width2;
public:
	Fazzy_hairslab(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	//JIADE
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	//JIADE
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};

class Fazzy_mesoscutum :public FazzyModel {
	double r;
	const double ep1, ep2;
	const int width1, width2;
public:
	Fazzy_mesoscutum(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	//JIADE
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	//JIADE
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};

class FazzyMieModel :public FazzyModel {
	double ep;
	double r;
public:
	FazzyMieModel(Field* f);
	string mkdir(string root);
	virtual void InitializeLambda(double a) {
		this->r = mField->nanoToCell(a);
		cout << "r=" + to_s((int)mField->cellToNano(r)) << endl;
	}

	double calcEPS(const double& x, const double& y, enum INTEG f);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	bool update(int a) {

		return false;
	}
	void Initialize()
	{
	}
};

class Fazzyfeather :public FazzyModel {
	double ep;
	double r;
public:
	Fazzyfeather(Field* f);
	string mkdir(string root);
	virtual void InitializeLambda(double a) {
		this->r = mField->nanoToCell(a);
		cout << "r=" + to_s((int)mField->cellToNano(r)) << endl;
	}

	double calcEPS(const double& x, const double& y, enum INTEG f);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	bool update(int a) {

		return false;
	}
	void Initialize()
	{
	}
};
class FazzyMorphoModel :public FazzyModel {
protected:
	int height[2];
	int min, max;
	int width;
	double e;
	int num;
	double ep[2];
	enum STRUCTURE shelf;	//屳偄堘偄偐偳偆偐
public:
	FazzyMorphoModel(Field* , double _h0, double _h1, enum STRUCTURE kind);

	string mkdir(string root);

	double calcEPS(const double &x, const double &y, enum INTEG f);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	bool update(int dh);

	void Initialize() {
		height[1] = min;
		height[0] = min;
	}
};

class FazzyNoModel :public FazzyModel {
public:
	FazzyNoModel(Field* f)
		:FazzyModel(f)
	{
	}

	string mkdir(string root);

	double calcEPS(const double &x, const double &y, enum INTEG f) {
		return EPSILON_0_S;
	}
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	bool update(int a) {
		return true;
	}

	void Initialize()
	{

	}

};
//the simulation parameter of BuprestidaeModel is (2038, 2038, 2, 20),the parameter of the field
class SapphirinidModelSmooth :public FazzyModel {
	const double epOfCrystal, epOfCytoplasm;

	double lambda, w;

public:
	SapphirinidModelSmooth(Field*, double);
	string mkdir(string root);
	double calcEPS(const double& x, const double& y, enum INTEG f = D_XY);
	double calcSIG(const double& x, const double& y, const double lam, enum INTEG f = D_XY);
	double calcMultilayer(double x, double y, double start);
	double selectLayer(double x, double start);

	void setLambda(double i) {
		this->lambda = i;
		w = LIGHT_SPEED_S * (2 * PI / lambda);

	}
	bool update(int) {
		return false;
	}

	void Initialize() {
	}
};

class FazzyHair_CrossSection :public FazzyModel {
	const double  ep_cor, ep_air, e, ep_cuti, ep_med;
	double r;
	double rn, ax, by;
public:
	FazzyHair_CrossSection(Field*);
	string mkdir(string root);

	virtual void InitializeLambda(double a) {
		this->r = mField->nanoToCell(a);
		cout << "r=" + to_s((int)mField->cellToNano(r)) << endl;
	}
	double calcEPS(const double&, const double&, enum INTEG f);
	//JIADE
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	//JIADE
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};
class FazzyHair_incidenceModel :public FazzyModel {
	const double ep1, ep2;
	const int alpha;
	double alphaR, length, ln, lx, ly, rn, cwidth, r;
public:
	FazzyHair_incidenceModel(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY);
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};

class FazzyHair_incidenceLayerModel :public FazzyModel {
	const double ep1, ep2;
	const int alpha;
	double alphaR, r, rn, cwidth, cn, cmc, mn, length, ln, lx, ly;
	/*
	alpha:孹偒		alphaR:孹偒(儔僕傾儞)
	r:栄旂幙斖埻偺敿宎(兪m)							rn:栄旂幙斖埻偺敿宎(nm僔儈儏儗乕僔儑儞抣)
	cwidth:僉儏乕僥傿僋儖岤偝(兪m)					cn:僉儏乕僥傿僋儖岤偝(nm僔儈儏儗乕僔儑儞抣)
	cmc:CMC暆(兪m)									mn:CMC暆(nm僔儈儏儗乕僔儑儞抣)
	length:僉儏乕僥傿僋儖挿偝(兪m)					ln:僉儏乕僥傿僋儖挿偝(nm僔儈儏儗乕僔儑儞抣)
	ly:僉儏乕僥傿僋儖斖埻(nm僔儈儏儗乕僔儑儞抣)		lx:x曽岦挿偝(nm僔儈儏儗乕僔儑儞抣)
	*/
public:
	FazzyHair_incidenceLayerModel(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY);
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};

class FazzyHair_simple_cuti_Model :public FazzyModel {
	const double ep1, ep2;
	const int alpha;
	double alphaR, r, rn, cwidth, cn, cmc, mn, length, ln, lx, ly,h_in,h_out,l_out;
	/*
	alpha:孹偒		alphaR:孹偒(儔僕傾儞)
	r:栄旂幙斖埻偺敿宎(兪m)							rn:栄旂幙斖埻偺敿宎(nm僔儈儏儗乕僔儑儞抣)
	cwidth:僉儏乕僥傿僋儖岤偝(兪m)					cn:僉儏乕僥傿僋儖岤偝(nm僔儈儏儗乕僔儑儞抣)
	cmc:CMC暆(兪m)									mn:CMC暆(nm僔儈儏儗乕僔儑儞抣)
	length:僉儏乕僥傿僋儖挿偝(兪m)					ln:僉儏乕僥傿僋儖挿偝(nm僔儈儏儗乕僔儑儞抣)
	ly:僉儏乕僥傿僋儖斖埻(nm僔儈儏儗乕僔儑儞抣)		lx:x曽岦挿偝(nm僔儈儏儗乕僔儑儞抣)
	*/
public:
	FazzyHair_simple_cuti_Model(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY);
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};
class FazzyHair_cuti_Model2 :public FazzyModel {
	const double ep1, ep2,e;
	const int alpha,beta;
	double alphaR, r, rn, cwidth, cn, cmc, mn, length, ln, lx, ly, h_in, h_out, l_out, h_cn, h_cnmn,ax,by,h_cnmn_up;
	/*
	alpha:孹偒		alphaR:孹偒(儔僕傾儞)
	r:栄旂幙斖埻偺敿宎(兪m)							rn:栄旂幙斖埻偺敿宎(nm僔儈儏儗乕僔儑儞抣)
	cwidth:僉儏乕僥傿僋儖岤偝(兪m)					cn:僉儏乕僥傿僋儖岤偝(nm僔儈儏儗乕僔儑儞抣)
	cmc:CMC暆(兪m)									mn:CMC暆(nm僔儈儏儗乕僔儑儞抣)
	length:僉儏乕僥傿僋儖挿偝(兪m)					ln:僉儏乕僥傿僋儖挿偝(nm僔儈儏儗乕僔儑儞抣)
	ly:僉儏乕僥傿僋儖斖埻(nm僔儈儏儗乕僔儑儞抣)		lx:x曽岦挿偝(nm僔儈儏儗乕僔儑儞抣)
	*/
public:
	FazzyHair_cuti_Model2(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY);
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};
class FazzyHair_cuti_only :public FazzyModel {
	const double ep1, ep2, e;
	const int alpha, beta;
	double alphaR, r, rn, cwidth, cn, cmc, mn, length, ln, lx, ly, h_in, h_out, l_out, h_cn, h_cnmn, ax, by, h_cnmn_up;
	/*
	alpha:孹偒		alphaR:孹偒(儔僕傾儞)
	r:栄旂幙斖埻偺敿宎(兪m)							rn:栄旂幙斖埻偺敿宎(nm僔儈儏儗乕僔儑儞抣)
	cwidth:僉儏乕僥傿僋儖岤偝(兪m)					cn:僉儏乕僥傿僋儖岤偝(nm僔儈儏儗乕僔儑儞抣)
	cmc:CMC暆(兪m)									mn:CMC暆(nm僔儈儏儗乕僔儑儞抣)
	length:僉儏乕僥傿僋儖挿偝(兪m)					ln:僉儏乕僥傿僋儖挿偝(nm僔儈儏儗乕僔儑儞抣)
	ly:僉儏乕僥傿僋儖斖埻(nm僔儈儏儗乕僔儑儞抣)		lx:x曽岦挿偝(nm僔儈儏儗乕僔儑儞抣)
	*/
public:
	FazzyHair_cuti_only(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY);
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};


class FazzyHair_cuti_damage :public FazzyModel {
	const double ep1, ep2, e;
	const int alpha;
	double initalphaR,alphaR, alphaR3,alphaR2, r, rn, cwidth, cn, cmc, mn, length, ln, normal_ln, lx, ly, normal_ly, normal_length, h_in, h_out, l_out, h_cn, h_cnmn, ax, by, h_cnmn_up, normal_h_cn, normal_h_cnmn;

public:
	FazzyHair_cuti_damage(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY);
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};
class FazzyHair_cuti_edage :public FazzyModel {
	const double ep1, ep2, e;
	const int alpha,beta;
	double initalphaR, alphaR, alphaR3, alphaR2, r, rn, cwidth, cn, cmc, mn, length, ln, normal_ln, lx, ly, normal_ly, normal_length, h_in, h_out, l_out, h_cn, h_cnmn, ax, by, h_cnmn_up, normal_h_cn, normal_h_cnmn;

public:
	FazzyHair_cuti_edage(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY);
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};

class FazzyHair_cuti_Model :public FazzyModel {
	const double ep1, ep2;
	const int alpha;
	double alphaR, r, rn, cwidth, cn, cmc, mn, length, ln, lx, ly, h_in, h_out, l_out, h_cn, h_cnmn;
	/*
	alpha:孹偒		alphaR:孹偒(儔僕傾儞)
	r:栄旂幙斖埻偺敿宎(兪m)							rn:栄旂幙斖埻偺敿宎(nm僔儈儏儗乕僔儑儞抣)
	cwidth:僉儏乕僥傿僋儖岤偝(兪m)					cn:僉儏乕僥傿僋儖岤偝(nm僔儈儏儗乕僔儑儞抣)
	cmc:CMC暆(兪m)									mn:CMC暆(nm僔儈儏儗乕僔儑儞抣)
	length:僉儏乕僥傿僋儖挿偝(兪m)					ln:僉儏乕僥傿僋儖挿偝(nm僔儈儏儗乕僔儑儞抣)
	ly:僉儏乕僥傿僋儖斖埻(nm僔儈儏儗乕僔儑儞抣)		lx:x曽岦挿偝(nm僔儈儏儗乕僔儑儞抣)
	*/
public:
	FazzyHair_cuti_Model(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG = D_XY);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY);
	
	
	void Initialize()
	{
	}
};

class FazzyHair_normalModel :public FazzyModel {
	const double ep1, ep2, e;
	const int r;
	double rn, ax, by;
public:
	FazzyHair_normalModel(Field*);
	string mkdir(string root);
	double calcEPS(const double&, const double&, enum INTEG f);
	//JIADE
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY) {
		return 0;
	}
	//JIADE
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};



class FazzyHair_NONcuticleModel :public FazzyModel {
	const double ep1, ep2;
	const int r;
	double rn;
public:
	FazzyHair_NONcuticleModel(Field*);
	string mkdir(string root);
    double calcEPS(const double&, const double&, enum INTEG = D_XY);
	double calcSIG(const double&, const double&, const double lam, enum INTEG = D_XY);
	bool update(int) {
		//return true;
		return false;
	}
	void Initialize()
	{
	}
};



/*
	virtual void InitializeLambda(double a) {
#define CRYSTAL true
#define CYTOPLASM false
		setLambda(a);
		epOfCrystal = calcEPSFromN(CRYSTAL);
		epOfCytoplasm = calcEPSFromN(CYTOPLASM);
		sigOfCrystal = calcSIGFromN(CRYSTAL);
		sigOfCytoplasm = calcSIGFromN(CYTOPLASM);
		cout << "epw=" << epOfCrystal << " epb=" << epOfCytoplasm << endl;
		cout << "sigw=" << sigOfCrystal << " sigb=" << sigOfCytoplasm << endl;
	}
	double getNByLambda(double a[]) {
		if (lambda >= 650)
			return a[5] + (lambda - 650)*(a[6] - a[5]) / 50;
		if (lambda >= 600)
			return a[4] + (lambda - 600)*(a[5] - a[4]) / 50;
		if (lambda >= 550)
			return a[3] + (lambda - 550)*(a[4] - a[3]) / 50;
		if (lambda >= 500)
			return a[2] + (lambda - 500)*(a[3] - a[2]) / 50;
		if (lambda >= 450)
			return a[1] + (lambda - 450)*(a[2] - a[1]) / 50;
		if (lambda >= 400)
			return a[0] + (lambda - 400)*(a[1] - a[0]) / 50;

		return 0.0;
	}

*/
//the simulation parameter of BuprestidaeModel is (2038, 2038, 2, 20),the parameter of the field
class BuprestidaeModel :public FazzyModel {
	double epOfWhite, epOfBlack;
	double sigOfWhite, sigOfBlack;
	double realPartOfWhite[7];
	double imaginaryPartOfWhite[7];
	double realPartOfBlack[7];
	double imaginaryPartOfBlack[7];
	double lambda, w;
public:
	BuprestidaeModel(Field*, double);
	string mkdir(string root);
	double calcEPS(const double& x, const double& y, enum INTEG f = D_XY);
	double calcSIG(const double& x, const double& y, const double lam, enum INTEG f = D_XY);
	double calcEPSFromN(bool white);
	double calcSIGFromN(bool white);
	double initializeRoW(int i);
	double initializeRoB(int i);
	double initializeIoW(int i);
	double initializeIoB(int i);
	virtual void InitializeLambda(double a) {
        #define WHITE true
        #define BLACK false
		setLambda(a);
		epOfWhite = calcEPSFromN(WHITE);
		epOfBlack = calcEPSFromN(BLACK);
		sigOfWhite = calcSIGFromN(WHITE);
		sigOfBlack = calcSIGFromN(BLACK);
		cout << "epw=" << epOfWhite << " epb=" << epOfBlack << endl;
		cout << "sigw=" << sigOfWhite << " sigb=" << sigOfBlack << endl;
	}
	double getNByLambda(double a[]) {
		if (lambda >= 650)
			return a[5] + (lambda - 650)*(a[6] - a[5]) / 50;
		if (lambda >= 600)
			return a[4] + (lambda - 600)*(a[5] - a[4]) / 50;
		if (lambda >= 550)
			return a[3] + (lambda - 550)*(a[4] - a[3]) / 50;
		if (lambda >= 500)
			return a[2] + (lambda - 500)*(a[3] - a[2]) / 50;
		if (lambda >= 450)
			return a[1] + (lambda - 450)*(a[2] - a[1]) / 50;
		if (lambda >= 400)
			return a[0] + (lambda - 400)*(a[1] - a[0]) / 50;

		return 0.0;
	}
	void setLambda(double i) {
		this->lambda = i;
		w = LIGHT_SPEED_S * (2 * PI / lambda);
		
	}
	
	bool update(int) {
		return false;
	}

	void Initialize() {
	}
};

/*
simulation field (1700,1700,5,20)
*/

class BuprestidaeModelWithNoise :public FazzyModel {

	double epOfWhite, epOfBlack;
	double sigOfWhite, sigOfBlack;
	double realPartOfWhite[7];
	double imaginaryPartOfWhite[7];
	double realPartOfBlack[7];
	double imaginaryPartOfBlack[7];
	double lambda, w;
public:
	BuprestidaeModelWithNoise(Field*, double);
	string mkdir(string root);
	double calcEPS(const double& x, const double& y, enum INTEG f = D_XY);
	double calcSIG(const double& x, const double& y, const double lam, enum INTEG f = D_XY);
	double calcEPSFromN(bool white);
	double calcSIGFromN(bool white);
	double initializeRoW(int i);
	double initializeRoB(int i);
	double initializeIoW(int i);
	double initializeIoB(int i);
	double calcMultilayer(double x, double y,double start);
	double selectLayer(double x, double start);
	virtual void InitializeLambda(double a) {
#define WHITE true
#define BLACK false
		setLambda(a);
		epOfWhite = calcEPSFromN(WHITE);
		epOfBlack = calcEPSFromN(BLACK);
		sigOfWhite = calcSIGFromN(WHITE);
		sigOfBlack = calcSIGFromN(BLACK);
		cout << "epw=" << epOfWhite << " epb=" << epOfBlack << endl;
		cout << "sigw=" << sigOfWhite << " sigb=" << sigOfBlack << endl;
	}
	double getNByLambda(double a[]) {
		if (lambda >= 650)
			return a[5] + (lambda - 650)*(a[6] - a[5]) / 50;
		if (lambda >= 600)
			return a[4] + (lambda - 600)*(a[5] - a[4]) / 50;
		if (lambda >= 550)
			return a[3] + (lambda - 550)*(a[4] - a[3]) / 50;
		if (lambda >= 500)
			return a[2] + (lambda - 500)*(a[3] - a[2]) / 50;
		if (lambda >= 450)
			return a[1] + (lambda - 450)*(a[2] - a[1]) / 50;
		if (lambda >= 400)
			return a[0] + (lambda - 400)*(a[1] - a[0]) / 50;

		return 0.0;
	}
	void setLambda(double i) {
		this->lambda = i;
		w = LIGHT_SPEED_S * (2 * PI / lambda);

	}

	bool update(int) {
		return false;
	}

	void Initialize() {
	}

};

//1865,1865,5,20
class BuprestidaeModelsmooth2nd :public FazzyModel {
	double epOfWhite, epOfBlack;
	double sigOfWhite, sigOfBlack;
	double realPartOfWhite[7];
	double imaginaryPartOfWhite[7];
	double realPartOfBlack[7];
	double imaginaryPartOfBlack[7];
	double lambda, w;
public:
	BuprestidaeModelsmooth2nd(Field*, double);
	string mkdir(string root);
	double calcEPS(const double& x, const double& y, enum INTEG f = D_XY);
	double calcSIG(const double& x, const double& y, const double lam, enum INTEG f = D_XY);
	double calcEPSFromN(bool white);
	double calcSIGFromN(bool white);
	double initializeRoW(int i);
	double initializeRoB(int i);
	double initializeIoW(int i);
	double initializeIoB(int i);
	double calcMultilayer(double x, double y, double start);
	double selectLayer(double x, double start);
	virtual void InitializeLambda(double a) {
#define WHITE true
#define BLACK false
		setLambda(a);
		epOfWhite = calcEPSFromN(WHITE);
		epOfBlack = calcEPSFromN(BLACK);
		sigOfWhite = calcSIGFromN(WHITE);
		sigOfBlack = calcSIGFromN(BLACK);
		cout << "epw=" << epOfWhite << " epb=" << epOfBlack << endl;
		cout << "sigw=" << sigOfWhite << " sigb=" << sigOfBlack << endl;
	}
	double getNByLambda(double a[]) {
		if (lambda >= 650)
			return a[5] + (lambda - 650)*(a[6] - a[5]) / 50;
		if (lambda >= 600)
			return a[4] + (lambda - 600)*(a[5] - a[4]) / 50;
		if (lambda >= 550)
			return a[3] + (lambda - 550)*(a[4] - a[3]) / 50;
		if (lambda >= 500)
			return a[2] + (lambda - 500)*(a[3] - a[2]) / 50;
		if (lambda >= 450)
			return a[1] + (lambda - 450)*(a[2] - a[1]) / 50;
		if (lambda >= 400)
			return a[0] + (lambda - 400)*(a[1] - a[0]) / 50;

		return 0.0;
	}
	void setLambda(double i) {
		this->lambda = i;
		w = LIGHT_SPEED_S * (2 * PI / lambda);

	}

	bool update(int) {
		return false;
	}

	void Initialize() {
	}
};

//field(1845,1845,5,20)

class BuprestidaeModelWithNoise2nd :public FazzyModel {

	double epOfWhite, epOfBlack;
	double sigOfWhite, sigOfBlack;
	double realPartOfWhite[7];
	double imaginaryPartOfWhite[7];
	double realPartOfBlack[7];
	double imaginaryPartOfBlack[7];
	double lambda, w;
public:
	BuprestidaeModelWithNoise2nd(Field*, double);
	string mkdir(string root);
	double calcEPS(const double& x, const double& y, enum INTEG f = D_XY);
	double calcSIG(const double& x, const double& y, const double lam, enum INTEG f = D_XY);
	double calcEPSFromN(bool white);
	double calcSIGFromN(bool white);
	double initializeRoW(int i);
	double initializeRoB(int i);
	double initializeIoW(int i);
	double initializeIoB(int i);
	double calcMultilayer(double x, double y, double start);
	double selectLayer(double x, double start);
	virtual void InitializeLambda(double a) {
#define WHITE true
#define BLACK false
		setLambda(a);
		epOfWhite = calcEPSFromN(WHITE);
		epOfBlack = calcEPSFromN(BLACK);
		sigOfWhite = calcSIGFromN(WHITE);
		sigOfBlack = calcSIGFromN(BLACK);
		cout << "epw=" << epOfWhite << " epb=" << epOfBlack << endl;
		cout << "sigw=" << sigOfWhite << " sigb=" << sigOfBlack << endl;
	}
	double getNByLambda(double a[]) {
		if (lambda >= 650)
			return a[5] + (lambda - 650)*(a[6] - a[5]) / 50;
		if (lambda >= 600)
			return a[4] + (lambda - 600)*(a[5] - a[4]) / 50;
		if (lambda >= 550)
			return a[3] + (lambda - 550)*(a[4] - a[3]) / 50;
		if (lambda >= 500)
			return a[2] + (lambda - 500)*(a[3] - a[2]) / 50;
		if (lambda >= 450)
			return a[1] + (lambda - 450)*(a[2] - a[1]) / 50;
		if (lambda >= 400)
			return a[0] + (lambda - 400)*(a[1] - a[0]) / 50;

		return 0.0;
	}
	void setLambda(double i) {
		this->lambda = i;
		w = LIGHT_SPEED_S * (2 * PI / lambda);

	}

	bool update(int) {
		return false;
	}

	void Initialize() {
	}

};


//field(2345,2345,5)
class BuprestidaeModelSmooth24 :public FazzyModel {

	double epOfWhite, epOfBlack;
	double sigOfWhite, sigOfBlack;
	double realPartOfWhite[7];
	double imaginaryPartOfWhite[7];
	double realPartOfBlack[7];
	double imaginaryPartOfBlack[7];
	double lambda, w;
public:
	BuprestidaeModelSmooth24(Field*, double);
	string mkdir(string root);
	double calcEPS(const double& x, const double& y, enum INTEG f = D_XY);
	double calcSIG(const double& x, const double& y, const double lam, enum INTEG f = D_XY);
	double calcEPSFromN(bool white);
	double calcSIGFromN(bool white);
	double initializeRoW(int i);
	double initializeRoB(int i);
	double initializeIoW(int i);
	double initializeIoB(int i);
	double calcMultilayer(double x, double y, double start);
	double selectLayer(double x, double start);
	virtual void InitializeLambda(double a) {
#define WHITE true
#define BLACK false
		setLambda(a);
		epOfWhite = calcEPSFromN(WHITE);
		epOfBlack = calcEPSFromN(BLACK);
		sigOfWhite = calcSIGFromN(WHITE);
		sigOfBlack = calcSIGFromN(BLACK);
		cout << "epw=" << epOfWhite << " epb=" << epOfBlack << endl;
		cout << "sigw=" << sigOfWhite << " sigb=" << sigOfBlack << endl;
	}
	double getNByLambda(double a[]) {
		if (lambda >= 650)
			return a[5] + (lambda - 650)*(a[6] - a[5]) / 50;
		if (lambda >= 600)
			return a[4] + (lambda - 600)*(a[5] - a[4]) / 50;
		if (lambda >= 550)
			return a[3] + (lambda - 550)*(a[4] - a[3]) / 50;
		if (lambda >= 500)
			return a[2] + (lambda - 500)*(a[3] - a[2]) / 50;
		if (lambda >= 450)
			return a[1] + (lambda - 450)*(a[2] - a[1]) / 50;
		if (lambda >= 400)
			return a[0] + (lambda - 400)*(a[1] - a[0]) / 50;

		return 0.0;
	}
	void setLambda(double i) {
		this->lambda = i;
		w = LIGHT_SPEED_S * (2 * PI / lambda);

	}

	bool update(int) {
		return false;
	}

	void Initialize() {
	}

};



#endif //_MODEL_H