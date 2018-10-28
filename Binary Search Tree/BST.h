//---------------------------------------------------------------------------

#ifndef BSTH
#define BSTH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DockTabSet.hpp>
#include <Vcl.Tabs.hpp>

//---------------------------------------------------------------------------
class Twindow : public TForm
{
__published:	// IDE-managed Components
	TEdit *data;
	TButton *insertData;
	TMemo *output;
	TButton *inorderTraversal;
	TButton *preorderTraversal;
	TButton *postorderTraversal;
	TEdit *numOfNode;
	TButton *addRandomNode;
	TEdit *min;
	TEdit *max;
	TTrackBar *maxTrackBar;
	TTrackBar *minTrackBar;
	TLabel *Randon_range;
	TLabel *From;
	TLabel *To;
	TButton *searchBST;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *removeData;
	TEdit *infix;
	TEdit *prefix;
	TButton *infix_prefix;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *postfix;
	TLabel *Label7;
	TButton *infix_postfix;
	TButton *addHeap;
	TButton *delHeap;
	TButton *addRdmHeap;
	TButton *heap_Sort_btn;
	void __fastcall insertDataClick(TObject *Sender);
	void __fastcall inorderTraversalClick(TObject *Sender);
	void __fastcall preorderTraversalClick(TObject *Sender);
	void __fastcall postorderTraversalClick(TObject *Sender);
	void __fastcall addRandomNodeClick(TObject *Sender);
	void __fastcall minTrackBarChange(TObject *Sender);
	void __fastcall minChange(TObject *Sender);
	void __fastcall maxTrackBarChange(TObject *Sender);
	void __fastcall searchBSTClick(TObject *Sender);
	void __fastcall removeDataClick(TObject *Sender);
	void __fastcall infix_prefixClick(TObject *Sender);
	void __fastcall infix_postfixClick(TObject *Sender);
	void __fastcall addHeapClick(TObject *Sender);
	void __fastcall delHeapClick(TObject *Sender);
	void __fastcall addRdmHeapClick(TObject *Sender);
	void __fastcall heap_Sort_btnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Twindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Twindow *window;
//---------------------------------------------------------------------------
#endif
