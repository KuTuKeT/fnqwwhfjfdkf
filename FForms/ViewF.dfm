object FormViewF: TFormViewF
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  ClientHeight = 441
  ClientWidth = 780
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnShow = FormShow
  TextHeight = 15
  object Bevel_1: TBevel
    Left = 8
    Top = 282
    Width = 764
    Height = 15
    Shape = bsTopLine
  end
  object LabeCallState: TLabel
    Left = 567
    Top = 314
    Width = 87
    Height = 15
    Caption = #1057#1090#1072#1090#1091#1089' '#1086#1073#1088#1086#1073#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelProducts: TLabel
    Left = 240
    Top = 18
    Width = 117
    Height = 15
    Caption = #1058#1086#1074#1072#1088#1080' '#1091' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1110':'
  end
  object GroupBoxInfo: TGroupBox
    Left = 9
    Top = 18
    Width = 225
    Height = 186
    Caption = #1030#1085#1092#1086#1088#1084#1072#1094#1110#1103
    TabOrder = 0
    object LabeledEditID: TLabeledEdit
      Left = 20
      Top = 45
      Width = 177
      Height = 23
      EditLabel.Width = 38
      EditLabel.Height = 15
      EditLabel.Caption = #1053#1086#1084#1077#1088
      ReadOnly = True
      TabOrder = 0
      Text = ''
    end
    object LabeledEditStatus: TLabeledEdit
      Left = 20
      Top = 95
      Width = 177
      Height = 23
      EditLabel.Width = 36
      EditLabel.Height = 15
      EditLabel.Caption = #1057#1090#1072#1090#1091#1089
      ReadOnly = True
      TabOrder = 1
      Text = ''
    end
    object LabeledEditDateTime: TLabeledEdit
      Left = 20
      Top = 143
      Width = 177
      Height = 23
      EditLabel.Width = 61
      EditLabel.Height = 15
      EditLabel.Caption = #1044#1072#1090#1072' '#1090#1072' '#1095#1072#1089
      ReadOnly = True
      TabOrder = 2
      Text = ''
    end
  end
  object ButtonNotes: TButton
    Left = 9
    Top = 218
    Width = 225
    Height = 45
    Caption = #1047#1072#1084#1110#1090#1082#1080' '#1076#1086' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    StyleElements = [seFont, seBorder]
    OnClick = ButtonNotesClick
  end
  object GroupBoxCallComment: TGroupBox
    Left = 8
    Top = 303
    Width = 553
    Height = 126
    Caption = #1050#1086#1084#1077#1085#1090#1072#1088' '#1076#1086' '#1076#1079#1074#1110#1085#1082#1091
    TabOrder = 2
    object MemoCallComment: TMemo
      Left = 14
      Top = 24
      Width = 523
      Height = 90
      TabOrder = 0
    end
  end
  object ComboBoxCallState: TComboBox
    Left = 567
    Top = 335
    Width = 201
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Items.Strings = (
      #1047#1110#1073#1088#1072#1085#1086
      #1053#1072' '#1076#1086#1087#1088#1072#1094#1102#1074#1072#1085#1085#1103)
  end
  object ButtonConfirm: TButton
    Left = 567
    Top = 393
    Width = 201
    Height = 36
    Caption = #1055#1110#1076#1090#1074#1077#1088#1076#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    StyleElements = [seFont, seBorder]
    OnClick = ButtonConfirmClick
  end
  object ListViewProducts: TListView
    Left = 240
    Top = 39
    Width = 530
    Height = 224
    Columns = <
      item
        Caption = #1053#1072#1081#1084#1077#1085#1091#1074#1072#1085#1085#1103
        Width = 235
      end
      item
        Caption = #1043#1088#1091#1087#1087#1072
        Width = 160
      end
      item
        Caption = #1062#1110#1085#1072
        Width = 65
      end
      item
        Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100
        Width = 65
      end>
    TabOrder = 5
    ViewStyle = vsReport
  end
end
