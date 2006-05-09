// $Header$

#ifndef REVE_GuiPointSet_H
#define REVE_GuiPointSet_H

#include <Reve/PODs.h>
#include <Reve/RenderElement.h>

#include <TPointSet3D.h>

class TTree;
class TF3;
class TGListTreeItem;

namespace Reve {

class PointSet : public TPointSet3D, public RenderElement
{
  friend class PointSetArray;

private:
  void Init();

protected:
  TString fTitle;

public:
  enum TreeVarType_e { TVT_XYZ, TVT_RPhiZ };

  PointSet(Int_t n_points=0);
  PointSet(const Text_t* name, Int_t n_points=0);
  PointSet(const Text_t* name, TTree* tree,
		    TreeVarType_e tv_type=TVT_XYZ);

  void Reset(Int_t n_points=0);

  virtual const Text_t* GetTitle() const          { return fTitle; }
  virtual void          SetTitle(const Text_t* t) { fTitle = t; }

  virtual void SetMarkerColor(Color_t col)
  { SetMainColor(col); }

  virtual void Paint(Option_t* option="");

  ClassDef(PointSet, 1);
}; // endclass GuiPointSet

/**************************************************************************/

class PointSetArray : public TNamed, public RenderElementListBase
{
protected:
  PointSet**   fBins;
  Int_t        fNBins;
  Double_t     fMin, fCurMin;
  Double_t     fMax, fCurMax;
  Double_t     fBinWidth;
  TString      fQuantName;

  Color_t      fColor;

public:
  enum TreeVarType_e { TVT_XYZ, TVT_RPhiZ };

  PointSetArray(const Text_t* name="PointSetArray",
			const Text_t* title="");
  virtual ~PointSetArray();

  virtual Bool_t CanEditMainColor()           { return true; }
  virtual void   Paint(Option_t* option = "") { PaintElements(option); }

  void InitBins(TGListTreeItem* tree_item, const Text_t* quant_name,
		Int_t nbins, Double_t min, Double_t max);
  void Fill(Double_t quant, Double_t x, Double_t y, Double_t z);
  void Fill(TF3* formula, TTree* tree, TreeVarType_e tv_type=TVT_XYZ);
  void CloseBins(Int_t mark_style, Float_t mark_size);

  Double_t GetMin()    const { return fMin; }
  Double_t GetCurMin() const { return fCurMin; }
  Double_t GetMax()    const { return fMax; }
  Double_t GetCurMax() const { return fCurMax; }

  void SetRange(Double_t min, Double_t max);

  void MakeScrollbar(); // *MENU*
  void HandleScrollEvent();

  ClassDef(PointSetArray, 1);
};

}

#endif
