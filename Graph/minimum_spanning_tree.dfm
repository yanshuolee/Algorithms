object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Minimum Spanning Tree by Y.S.L'
  ClientHeight = 552
  ClientWidth = 652
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 249
    Top = 0
    Width = 8
    Height = 552
    ExplicitLeft = 245
    ExplicitHeight = 555
  end
  object PageControl1: TPageControl
    Left = 257
    Top = 0
    Width = 395
    Height = 552
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 0
    object TabSheet2: TTabSheet
      Caption = 'Minimum Spanning Tree'
      ImageIndex = 1
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 387
        Height = 524
        Align = alClient
        Lines.Strings = (
          '< Result >')
        TabOrder = 0
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Adjacent Matrix'
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 387
        Height = 524
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Adjacent List'
      ImageIndex = 2
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 387
        Height = 524
        Align = alClient
        TabOrder = 0
      end
    end
  end
  object ListBox1: TListBox
    Left = 0
    Top = 0
    Width = 249
    Height = 552
    Align = alLeft
    ItemHeight = 13
    TabOrder = 1
  end
  object StaticText2: TStaticText
    Left = 24
    Top = 91
    Width = 116
    Height = 17
    Caption = 'Range of Edge Weight:'
    TabOrder = 2
  end
  object threshold: TEdit
    Left = 85
    Top = 128
    Width = 57
    Height = 21
    TabOrder = 3
    Text = '60'
  end
  object StaticText3: TStaticText
    Left = 24
    Top = 132
    Width = 55
    Height = 17
    Caption = 'Threshold:'
    TabOrder = 4
  end
  object Button1: TButton
    Left = 46
    Top = 184
    Width = 94
    Height = 33
    Caption = 'Generate Graph'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 24
    Top = 313
    Width = 187
    Height = 33
    Caption = 'Kruskal'#39's Algorithm using Heap Sort'
    TabOrder = 6
  end
  object StaticText1: TStaticText
    Left = 24
    Top = 48
    Width = 92
    Height = 17
    Caption = 'Number of Vector:'
    TabOrder = 7
  end
  object rng_of_weight: TEdit
    Left = 146
    Top = 87
    Width = 52
    Height = 21
    TabOrder = 8
    Text = '100'
  end
  object num_of_vector: TEdit
    Left = 122
    Top = 44
    Width = 31
    Height = 21
    TabOrder = 9
    Text = '8'
  end
  object Button3: TButton
    Left = 24
    Top = 274
    Width = 187
    Height = 33
    Caption = 'Kruskal'#39's Algo using Selection Sort'
    TabOrder = 10
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 24
    Top = 352
    Width = 187
    Height = 33
    Caption = 'Prim'#39's Algorithm'
    TabOrder = 11
    OnClick = Button4Click
  end
  object CheckBox1: TCheckBox
    Left = 46
    Top = 243
    Width = 107
    Height = 17
    Caption = 'Print Edges in MST'
    Checked = True
    State = cbChecked
    TabOrder = 12
  end
end
