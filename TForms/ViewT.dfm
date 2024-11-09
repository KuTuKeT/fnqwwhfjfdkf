object FormViewT: TFormViewT
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  ClientHeight = 473
  ClientWidth = 710
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
    Left = 11
    Top = 306
    Width = 687
    Height = 15
    Shape = bsTopLine
  end
  object LabeCallState: TLabel
    Left = 476
    Top = 338
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
  object GroupBoxInfo: TGroupBox
    Left = 11
    Top = 18
    Width = 456
    Height = 138
    Caption = #1030#1085#1092#1086#1088#1084#1072#1094#1110#1103
    TabOrder = 0
    object LabelTimePicker: TLabel
      Left = 251
      Top = 77
      Width = 72
      Height = 15
      Caption = #1063#1072#1089' '#1076#1086#1089#1090#1072#1074#1082#1080
    end
    object LabelDatePicker: TLabel
      Left = 251
      Top = 27
      Width = 77
      Height = 15
      Caption = #1044#1072#1090#1072' '#1076#1086#1089#1090#1072#1074#1082#1080
    end
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
    object DatePicker: TDateTimePicker
      Left = 251
      Top = 45
      Width = 177
      Height = 23
      Date = 36892.000000000000000000
      Format = 'dd.MM.yyyy'
      Time = 36892.000000000000000000
      TabOrder = 2
    end
    object StartTimePicker: TDateTimePicker
      Left = 251
      Top = 95
      Width = 85
      Height = 23
      Date = 36892.000000000000000000
      Format = 'HH:mm'
      Time = 36892.000000000000000000
      Kind = dtkTime
      TabOrder = 3
    end
    object EndTimePicker: TDateTimePicker
      Left = 343
      Top = 95
      Width = 85
      Height = 23
      Date = 36892.000000000000000000
      Format = 'HH:mm'
      Time = 36892.000000000000000000
      Kind = dtkTime
      TabOrder = 4
    end
  end
  object ButtonNotes: TButton
    Left = 473
    Top = 162
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
  object GroupBoxRecipient: TGroupBox
    Left = 473
    Top = 18
    Width = 225
    Height = 138
    Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095
    TabOrder = 2
    object LabeledEditRecipientName: TLabeledEdit
      Left = 20
      Top = 45
      Width = 177
      Height = 23
      EditLabel.Width = 21
      EditLabel.Height = 15
      EditLabel.Caption = #1030#1084#39#1103
      ReadOnly = True
      TabOrder = 0
      Text = ''
    end
    object LabeledEditRecipientPhone: TLabeledEdit
      Left = 20
      Top = 95
      Width = 177
      Height = 23
      EditLabel.Width = 48
      EditLabel.Height = 15
      EditLabel.Caption = #1058#1077#1083#1077#1092#1086#1085
      ReadOnly = True
      TabOrder = 1
      Text = ''
    end
  end
  object GroupBoxAddress: TGroupBox
    Left = 11
    Top = 162
    Width = 456
    Height = 138
    Caption = #1040#1076#1088#1077#1089#1072
    TabOrder = 3
    object MemoAddress: TMemo
      Left = 16
      Top = 24
      Width = 425
      Height = 94
      TabOrder = 0
    end
  end
  object GroupBoxCallComment: TGroupBox
    Left = 11
    Top = 327
    Width = 459
    Height = 126
    Caption = #1050#1086#1084#1077#1085#1090#1072#1088' '#1076#1086' '#1076#1079#1074#1110#1085#1082#1091
    TabOrder = 4
    object MemoCallComment: TMemo
      Left = 14
      Top = 24
      Width = 430
      Height = 90
      TabOrder = 0
    end
  end
  object ComboBoxCallState: TComboBox
    Left = 476
    Top = 359
    Width = 222
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    Items.Strings = (
      #1055#1110#1076#1090#1074#1077#1088#1076#1078#1077#1085#1086
      #1053#1072' '#1076#1086#1087#1088#1072#1094#1102#1074#1072#1085#1085#1103)
  end
  object ButtonConfirm: TButton
    Left = 476
    Top = 417
    Width = 222
    Height = 36
    Caption = #1055#1110#1076#1090#1074#1077#1088#1076#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    StyleElements = [seFont, seBorder]
    OnClick = ButtonConfirmClick
  end
end
