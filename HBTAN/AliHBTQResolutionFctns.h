#ifndef ALIHBTQOUTVSQINVRESOLFCTN_H
#define ALIHBTQOUTVSQINVRESOLFCTN_H
//General Remark:
//CMSLC means
//Center of Mass System Longitudially Co-moving


//this class creates resolution function of Qout 
//(difference of simulated pair Qout and recontructed pair)
//in function of QInv
//it inherits from AliHBTTwoPairFctn2D
//  it needs two pairs to compare
//  and is two dimentional: numerator and denominator are TH2D

class AliHBTQOutResolVSQInvFctn;  //QOutCMSLC  Res   VS   QInvCMSLC 
class AliHBTQSideResolVSQInvFctn; //QSideCMSLC Res   VS   QInvCMSLC 
class AliHBTQLongResolVSQInvFctn; //QLongCMSLC Res   VS   QInvCMSLC 

class AliHBTQInvResolVSKtFctn;    //QInvCMSLC  Res   VS   Kt
class AliHBTQOutResolVSKtFctn;    //QOutCMSLC  Res   VS   Kt
class AliHBTQSideResolVSKtFctn;   //QSideCMSLC Res   VS   Kt
class AliHBTQLongResolVSKtFctn;   //QLongCMSLC Res   VS   Kt

class AliHBTQOutResolVSQOutFctn;  //QOutCMSLC  Res   VS   QOut
class AliHBTQSideResolVSQSideFctn;//QSideCMSLC Res   VS   QSide
class AliHBTQLongResolVSQLongFctn;//QLongCMSLC Res   VS   QLong


#include "AliHBTFunction.h"
/***********************************************************************/
/***********************************************************************/
class AliHBTQOutResolVSQInvFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQOutResolVSQInvFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                             Int_t nYbins = 500, Double_t maxYval = .15, Double_t minYval =-0.15);
   
   virtual ~AliHBTQOutResolVSQInvFctn(){}
   
   TH1* GetResult(){return fNumerator;}  
   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair, Double_t& x, Double_t& y)
    {
     y = partpair->GetQOutCMSLC() - trackpair->GetQOutCMSLC();
     x = partpair->GetQInv();
    }
  protected:
  private: 
  public:
    ClassDef(AliHBTQOutResolVSQInvFctn,1)
 };

/***********************************************************************/
/***********************************************************************/
class AliHBTQSideResolVSQInvFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQSideResolVSQInvFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                             Int_t nYbins = 500, Double_t maxYval = .05, Double_t minYval =-0.05);
   virtual ~AliHBTQSideResolVSQInvFctn(){}

   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair,  Double_t& x, Double_t& y)
    {
     y = partpair->GetQSideCMSLC() - trackpair->GetQSideCMSLC();
     x = partpair->GetQInv();
    }
   TH1* GetResult(){return fNumerator;} 
  protected:
  private:
  public:
    ClassDef(AliHBTQSideResolVSQInvFctn,1)
 };

/***********************************************************************/
/***********************************************************************/
class AliHBTQLongResolVSQInvFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQLongResolVSQInvFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                             Int_t nYbins = 500, Double_t maxYval = .05, Double_t minYval =-0.05);
   virtual ~AliHBTQLongResolVSQInvFctn(){}

   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair, Double_t& x, Double_t& y)
    {
     y = partpair->GetQLongCMSLC() - trackpair->GetQLongCMSLC();
     x = partpair->GetQInv();
    }
   TH1* GetResult(){return fNumerator;} 
  protected:
  private:
  public:
    ClassDef(AliHBTQLongResolVSQInvFctn,1)
 };

/***********************************************************************/
/***********************************************************************/
class AliHBTQInvResolVSKtFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQInvResolVSKtFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                             Int_t nYbins = 500, Double_t maxYval = .05, Double_t minYval =-0.05);
   virtual ~AliHBTQInvResolVSKtFctn(){};

   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair, Double_t& x, Double_t& y)
    {
     y = partpair->GetQInv() - trackpair->GetQInv();
     x = partpair->GetKt();
    }
   TH1* GetResult(){return fNumerator;} 
  protected:
  private:
  public:
    ClassDef(AliHBTQInvResolVSKtFctn,1)
 };
/***********************************************************************/
/***********************************************************************/
class AliHBTQOutResolVSKtFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQOutResolVSKtFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                             Int_t nYbins = 500, Double_t maxYval = .15, Double_t minYval =-0.15);
   virtual ~AliHBTQOutResolVSKtFctn(){}
   TH1* GetResult(){return GetNumerator();}
   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair, Double_t& x, Double_t& y)
    {
     y = partpair->GetQOutCMSLC() - trackpair->GetQOutCMSLC();
     x = partpair->GetKt();
    }
  protected:
  private:
  public:
    ClassDef(AliHBTQOutResolVSKtFctn,1)
 };
/***********************************************************************/
/***********************************************************************/
class AliHBTQSideResolVSKtFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQSideResolVSKtFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                            Int_t nYbins = 500, Double_t maxYval = .05, Double_t minYval =-0.05);
   virtual ~AliHBTQSideResolVSKtFctn(){}
   TH1* GetResult(){return GetNumerator();}
   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair, Double_t& x, Double_t& y)
    {
     y = partpair->GetQSideCMSLC() - trackpair->GetQSideCMSLC();
     x = partpair->GetKt();
    }
  protected:
  private:
  public:
    ClassDef(AliHBTQSideResolVSKtFctn,1)
 };
/***********************************************************************/
/***********************************************************************/
class AliHBTQLongResolVSKtFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQLongResolVSKtFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                             Int_t nYbins = 500, Double_t maxYval = .05, Double_t minYval =-0.05);
   virtual ~AliHBTQLongResolVSKtFctn(){}

   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair, Double_t& x, Double_t& y)
    {
     y = partpair->GetQLongCMSLC() - trackpair->GetQLongCMSLC();
     x = partpair->GetKt();
    }
   TH1* GetResult(){return fNumerator;}  
  protected:
  private:
  public:
    ClassDef(AliHBTQLongResolVSKtFctn,1)
 };
/***********************************************************************/
/***********************************************************************/
class AliHBTQOutResolVSQOutFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQOutResolVSQOutFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                             Int_t nYbins = 500, Double_t maxYval = .15, Double_t minYval =-0.15);
   virtual ~AliHBTQOutResolVSQOutFctn(){}

   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair, Double_t& x, Double_t& y)
    {
     x = partpair->GetQOutCMSLC();
     y = x - trackpair->GetQOutCMSLC();
    }
   TH1* GetResult(){return fNumerator;}  
  protected:
  private:
  public:
    ClassDef(AliHBTQOutResolVSQOutFctn,1)
 };

/***********************************************************************/
/***********************************************************************/

class AliHBTQSideResolVSQSideFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQSideResolVSQSideFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                             Int_t nYbins = 500, Double_t maxYval = .15, Double_t minYval =-0.15);
   virtual ~AliHBTQSideResolVSQSideFctn(){}

   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair, Double_t& x, Double_t& y)
    {
     x = partpair->GetQSideCMSLC();
     y = x - trackpair->GetQSideCMSLC();
    }
   TH1* GetResult(){return fNumerator;}  
  protected:
  private:
  public:
    ClassDef(AliHBTQSideResolVSQSideFctn,1)
 };


/***********************************************************************/
/***********************************************************************/

class AliHBTQLongResolVSQLongFctn: public AliHBTTwoPairFctn2D
 {
  public: 
   AliHBTQLongResolVSQLongFctn(Int_t nXbins = 200, Double_t maxXval = 1.5, Double_t minXval = 0.0, 
                             Int_t nYbins = 500, Double_t maxYval = .05, Double_t minYval =-0.05);
   virtual ~AliHBTQLongResolVSQLongFctn(){}

   void GetValues(AliHBTPair* trackpair, AliHBTPair* partpair, Double_t& x, Double_t& y)
    {
     x = partpair->GetQLongCMSLC();
     y = x - trackpair->GetQLongCMSLC();
    }
   TH1* GetResult(){return fNumerator;}  
  protected:
  private:
  public:
    ClassDef(AliHBTQLongResolVSQLongFctn,1)
 };



#endif
