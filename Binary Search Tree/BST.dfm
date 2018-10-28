object window: Twindow
  Left = 0
  Top = 165
  Caption = 'Binary Search Tree by Y.S.L'
  ClientHeight = 516
  ClientWidth = 622
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 8
    Top = 26
    Width = 27
    Height = 13
    Caption = 'Data:'
  end
  object From: TLabel
    Left = 7
    Top = 265
    Width = 24
    Height = 13
    Caption = 'From'
  end
  object Randon_range: TLabel
    Left = 12
    Top = 240
    Width = 72
    Height = 13
    Caption = 'Randon range:'
  end
  object To: TLabel
    Left = 18
    Top = 296
    Width = 12
    Height = 13
    Caption = 'To'
  end
  object Label1: TLabel
    Left = 12
    Top = 117
    Width = 99
    Height = 13
    Caption = 'Recursive Traversal:'
  end
  object Label3: TLabel
    Left = 9
    Top = 190
    Width = 43
    Height = 13
    Caption = 'Random:'
  end
  object Label5: TLabel
    Left = 21
    Top = 353
    Width = 24
    Height = 13
    Caption = 'infix:'
  end
  object Label6: TLabel
    Left = 13
    Top = 388
    Width = 32
    Height = 13
    Caption = 'prefix:'
  end
  object Label7: TLabel
    Left = 8
    Top = 420
    Width = 37
    Height = 13
    Caption = 'postfix:'
  end
  object data: TEdit
    Left = 37
    Top = 23
    Width = 43
    Height = 21
    TabOrder = 0
    Text = '50'
  end
  object output: TMemo
    Left = 264
    Top = 8
    Width = 361
    Height = 505
    Lines.Strings = (
      'Output:')
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object addHeap: TButton
    Left = 167
    Top = 8
    Width = 72
    Height = 25
    Caption = 'Insert Heap'
    TabOrder = 2
    OnClick = addHeapClick
  end
  object delHeap: TButton
    Left = 167
    Top = 39
    Width = 72
    Height = 25
    Caption = 'Delete Heap'
    TabOrder = 3
    OnClick = delHeapClick
  end
  object minTrackBar: TTrackBar
    Left = 37
    Top = 265
    Width = 150
    Height = 18
    Max = 1000
    Position = 100
    TabOrder = 4
    OnChange = minTrackBarChange
  end
  object postorderTraversal: TButton
    Left = 149
    Top = 136
    Width = 66
    Height = 33
    Caption = 'postorder'
    TabOrder = 5
    OnClick = postorderTraversalClick
  end
  object numOfNode: TEdit
    Left = 55
    Top = 187
    Width = 45
    Height = 21
    TabOrder = 6
    Text = '10'
  end
  object maxTrackBar: TTrackBar
    Left = 36
    Top = 296
    Width = 150
    Height = 21
    Max = 10000
    Min = 10
    Position = 1199
    TabOrder = 7
    OnChange = maxTrackBarChange
  end
  object preorderTraversal: TButton
    Left = 85
    Top = 136
    Width = 58
    Height = 33
    Caption = 'preorder'
    TabOrder = 8
    OnClick = preorderTraversalClick
  end
  object insertData: TButton
    Left = 86
    Top = 8
    Width = 66
    Height = 25
    Caption = 'Insert Data'
    TabOrder = 9
    OnClick = insertDataClick
  end
  object searchBST: TButton
    Left = 86
    Top = 39
    Width = 66
    Height = 25
    Caption = 'Search Data'
    TabOrder = 10
    OnClick = searchBSTClick
  end
  object max: TEdit
    Left = 192
    Top = 304
    Width = 45
    Height = 21
    TabOrder = 11
    Text = '1000'
  end
  object min: TEdit
    Left = 192
    Top = 266
    Width = 45
    Height = 21
    TabOrder = 12
    Text = '100'
    OnChange = minChange
  end
  object addRandomNode: TButton
    Left = 107
    Top = 185
    Width = 96
    Height = 25
    Caption = 'Add Rdm to Node'
    TabOrder = 13
    OnClick = addRandomNodeClick
  end
  object inorderTraversal: TButton
    Left = 22
    Top = 136
    Width = 57
    Height = 33
    Caption = 'inorder'
    TabOrder = 14
    OnClick = inorderTraversalClick
  end
  object removeData: TButton
    Left = 86
    Top = 76
    Width = 66
    Height = 25
    Caption = 'Delete Data'
    TabOrder = 15
    OnClick = removeDataClick
  end
  object infix: TEdit
    Left = 51
    Top = 350
    Width = 82
    Height = 21
    TabOrder = 16
    Text = 'HBJAFDGCE'
  end
  object prefix: TEdit
    Left = 51
    Top = 385
    Width = 82
    Height = 21
    TabOrder = 17
    Text = 'ABHJCDFGE'
  end
  object infix_prefix: TButton
    Left = 139
    Top = 367
    Width = 75
    Height = 25
    Caption = 'infix+prefix'
    TabOrder = 18
    OnClick = infix_prefixClick
  end
  object postfix: TEdit
    Left = 51
    Top = 420
    Width = 82
    Height = 21
    TabOrder = 19
    Text = 'HJBFGDECA'
  end
  object infix_postfix: TButton
    Left = 139
    Top = 398
    Width = 75
    Height = 25
    Caption = 'infix+postfix'
    TabOrder = 20
    OnClick = infix_postfixClick
  end
  object addRdmHeap: TButton
    Left = 106
    Top = 216
    Width = 97
    Height = 25
    Caption = 'Add Rdm to Heap'
    TabOrder = 21
    OnClick = addRdmHeapClick
  end
  object heap_Sort_btn: TButton
    Left = 167
    Top = 76
    Width = 75
    Height = 25
    Caption = 'Heap Sort'
    TabOrder = 22
    OnClick = heap_Sort_btnClick
  end
end
