//---------------------------------------------------------------------------

#ifndef minimum_spanning_treeH
#define minimum_spanning_treeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TEdit *num_of_vector;
	TStaticText *StaticText1;
	TEdit *rng_of_weight;
	TStaticText *StaticText2;
	TEdit *threshold;
	TStaticText *StaticText3;
	TButton *Button1;
	TButton *Button2;
	TListBox *ListBox1;
	TSplitter *Splitter1;
	TStringGrid *StringGrid1;
	TTabSheet *TabSheet2;
	TButton *Button3;
	TButton *Button4;
	TTabSheet *TabSheet3;
	TStringGrid *StringGrid2;
	TMemo *Memo1;
	TCheckBox *CheckBox1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
