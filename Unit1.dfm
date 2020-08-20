object Form1: TForm1
  Left = 196
  Top = 114
  Width = 776
  Height = 591
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  WindowState = wsMaximized
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 408
    Top = 32
    Width = 100
    Height = 250
  end
  object Image2: TImage
    Left = 536
    Top = 32
    Width = 100
    Height = 250
  end
  object Label1: TLabel
    Left = 408
    Top = 8
    Width = 31
    Height = 13
    Caption = #1048#1075#1088#1086#1082
  end
  object Label2: TLabel
    Left = 536
    Top = 8
    Width = 33
    Height = 13
    Caption = #1044#1080#1083#1077#1088
  end
  object Label3: TLabel
    Left = 408
    Top = 288
    Width = 241
    Height = 13
    AutoSize = False
  end
  object Button1: TButton
    Left = 264
    Top = 392
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 408
    Top = 310
    Width = 185
    Height = 43
    TabOrder = 1
  end
  object Button2: TButton
    Left = 144
    Top = 392
    Width = 75
    Height = 25
    Caption = 'create'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 368
    Top = 392
    Width = 75
    Height = 25
    Caption = 'delete '
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 464
    Top = 392
    Width = 75
    Height = 25
    Caption = 'view'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 576
    Top = 392
    Width = 75
    Height = 25
    Caption = 'check!'
    TabOrder = 5
    OnClick = Button5Click
  end
  object Button7: TButton
    Left = 592
    Top = 432
    Width = 75
    Height = 25
    Caption = 'Stop it!'
    TabOrder = 6
    OnClick = Button7Click
  end
  object RadioGroup1: TRadioGroup
    Left = 2
    Top = 1
    Width = 136
    Height = 257
    Caption = #1050#1086#1084#1073#1080#1085#1072#1094#1080#1103
    ItemIndex = 0
    Items.Strings = (
      #1058#1091#1079'-'#1050#1086#1088#1086#1083#1100
      #1055#1072#1088#1072
      #1044#1074#1077' '#1087#1072#1088#1099
      #1058#1088#1086#1081#1085#1103
      #1057#1090#1088#1077#1081#1090
      #1060#1083#1101#1096
      #1048#1075#1088#1072
      #1053#1077#1090' '#1080#1075#1088#1099)
    TabOrder = 7
  end
  object Button6: TButton
    Left = 144
    Top = 432
    Width = 75
    Height = 25
    Caption = 'Game'
    TabOrder = 8
    OnClick = Button6Click
  end
  object Button8: TButton
    Left = 224
    Top = 432
    Width = 75
    Height = 25
    Caption = 'Sets'
    TabOrder = 9
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 144
    Top = 464
    Width = 75
    Height = 25
    Caption = 'Del game'
    TabOrder = 10
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 304
    Top = 432
    Width = 75
    Height = 25
    Caption = '2 '#1085#1072#1073#1086#1088#1072
    TabOrder = 11
    OnClick = Button10Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 526
    Width = 768
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object Button11: TButton
    Left = 384
    Top = 432
    Width = 75
    Height = 25
    Caption = #1057#1088#1072#1074#1085#1080#1090#1100
    TabOrder = 13
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 464
    Top = 432
    Width = 75
    Height = 25
    Caption = 'check!'
    TabOrder = 14
    OnClick = Button12Click
  end
  object Chart1: TChart
    Left = 144
    Top = 6
    Width = 257
    Height = 323
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    Legend.Visible = False
    View3D = False
    View3DWalls = False
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 15
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Style = smsValue
      Marks.Visible = False
      SeriesColor = clRed
      ShowInLegend = False
      Dark3D = False
      Pointer.Brush.Color = 4194368
      Pointer.HorizSize = 2
      Pointer.InflateMargins = False
      Pointer.Pen.Visible = False
      Pointer.Style = psRectangle
      Pointer.VertSize = 2
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object RadioGroup2: TRadioGroup
    Left = 2
    Top = 257
    Width = 136
    Height = 73
    Caption = #1054#1073#1084#1077#1085#1099
    ItemIndex = 0
    Items.Strings = (
      #1053#1077#1090' '
      #1054#1076#1080#1085
      #1044#1074#1072)
    TabOrder = 16
  end
  object RadioGroup3: TRadioGroup
    Left = 0
    Top = 336
    Width = 137
    Height = 73
    Caption = #1041#1086#1082#1089#1099
    ItemIndex = 0
    Items.Strings = (
      #1054#1076#1080#1085' '#1073#1086#1082#1089
      #1044#1074#1072' '#1073#1086#1082#1089#1072)
    TabOrder = 17
  end
  object Button13: TButton
    Left = 464
    Top = 464
    Width = 75
    Height = 25
    Caption = '100 '#1080#1075#1088
    TabOrder = 18
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 544
    Top = 464
    Width = 75
    Height = 25
    Caption = 'Game Step'
    TabOrder = 19
    OnClick = Button14Click
  end
  object MainMenu1: TMainMenu
    Left = 240
    Top = 16
    object File1: TMenuItem
      Caption = 'File'
      Enabled = False
    end
  end
end
