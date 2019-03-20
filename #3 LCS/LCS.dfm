object Form1: TForm1
  Left = 0
  Top = 0
  Caption = '#3 Longest Common Subsequences by Y.S.L Mar 3, 2019'
  ClientHeight = 479
  ClientWidth = 562
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
    Left = 0
    Top = 105
    Width = 562
    Height = 10
    Cursor = crVSplit
    Align = alTop
    ExplicitLeft = 8
    ExplicitTop = 96
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 562
    Height = 105
    Align = alTop
    TabOrder = 0
    object Edit1: TEdit
      Left = 16
      Top = 32
      Width = 273
      Height = 21
      TabOrder = 0
      Text = 'AVJDCLVGFD'
    end
    object Edit2: TEdit
      Left = 16
      Top = 59
      Width = 273
      Height = 21
      TabOrder = 1
      Text = 'DKKJDKKC'
    end
    object Button1: TButton
      Left = 304
      Top = 45
      Width = 75
      Height = 25
      Caption = 'LCS'
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 115
    Width = 562
    Height = 364
    Align = alClient
    Caption = 'Panel4'
    TabOrder = 1
    ExplicitTop = 119
    ExplicitHeight = 356
    object Splitter2: TSplitter
      Left = 441
      Top = 1
      Width = 10
      Height = 362
      ExplicitLeft = 369
      ExplicitHeight = 354
    end
    object Panel2: TPanel
      Left = 1
      Top = 1
      Width = 440
      Height = 362
      Align = alLeft
      Caption = 'Panel2'
      TabOrder = 0
      ExplicitHeight = 354
      object StringGrid1: TStringGrid
        Left = 1
        Top = 1
        Width = 438
        Height = 360
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 96
        ExplicitHeight = 352
      end
    end
    object Panel3: TPanel
      Left = 451
      Top = 1
      Width = 110
      Height = 362
      Align = alClient
      Caption = 'Panel3'
      TabOrder = 1
      ExplicitLeft = 192
      ExplicitTop = 160
      ExplicitWidth = 185
      ExplicitHeight = 41
      object Memo1: TMemo
        Left = 1
        Top = 1
        Width = 108
        Height = 360
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
        ExplicitLeft = 8
        ExplicitTop = 136
        ExplicitWidth = 185
        ExplicitHeight = 89
      end
    end
  end
end
