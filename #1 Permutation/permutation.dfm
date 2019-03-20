object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = '#1 Permutation by Y.S.L Feb 2, 2019'
  ClientHeight = 509
  ClientWidth = 273
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 19
    Width = 36
    Height = 13
    Caption = 'Text = '
  end
  object Edit1: TEdit
    Left = 74
    Top = 16
    Width = 94
    Height = 21
    TabOrder = 0
    Text = 'ABCD'
  end
  object Memo1: TMemo
    Left = 0
    Top = 64
    Width = 273
    Height = 445
    Align = alBottom
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Button1: TButton
    Left = 174
    Top = 14
    Width = 75
    Height = 25
    Caption = 'Permutation'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
end
