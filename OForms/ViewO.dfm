object FormViewO: TFormViewO
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  ClientHeight = 659
  ClientWidth = 855
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnShow = FormShow
  TextHeight = 15
  object LabelProducts: TLabel
    Left = 242
    Top = 161
    Width = 117
    Height = 15
    Caption = #1058#1086#1074#1072#1088#1080' '#1091' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1110':'
  end
  object Bevel_1: TBevel
    Left = 11
    Top = 501
    Width = 833
    Height = 15
    Shape = bsTopLine
  end
  object LabeCallState: TLabel
    Left = 643
    Top = 525
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
  object ListViewProducts: TListView
    Left = 242
    Top = 182
    Width = 602
    Height = 163
    Columns = <
      item
        Caption = #1053#1086#1084#1077#1088
        Width = 65
      end
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
    ReadOnly = True
    TabOrder = 0
    ViewStyle = vsReport
    OnDblClick = ListViewProductsDblClick
  end
  object GroupBoxRecipient: TGroupBox
    Left = 11
    Top = 351
    Width = 225
    Height = 135
    Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095
    TabOrder = 1
    object LabelChoiceRecipient: TLabel
      Left = 20
      Top = 27
      Width = 62
      Height = 15
      Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095
    end
    object ComboBoxChoiceRecipient: TComboBox
      Left = 20
      Top = 48
      Width = 177
      Height = 23
      TabOrder = 0
      Text = 'ComboBoxChoiceRecipient'
    end
    object ButtonAddRecipient: TButton
      Left = 20
      Top = 88
      Width = 177
      Height = 30
      Caption = #1044#1086#1076#1072#1090#1080' '#1086#1090#1088#1080#1084#1091#1074#1072#1095#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      StyleElements = [seFont, seBorder]
      OnClick = ButtonAddRecipientClick
    end
  end
  object ButtonNotes: TButton
    Left = 634
    Top = 447
    Width = 210
    Height = 42
    Caption = #1047#1072#1084#1110#1090#1082#1080' '#1076#1086' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    StyleElements = [seFont, seBorder]
    OnClick = ButtonNotesClick
  end
  object GroupBoxComment: TGroupBox
    Left = 473
    Top = 18
    Width = 371
    Height = 135
    Caption = #1050#1086#1084#1077#1085#1090#1072#1088' '#1076#1086' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
    TabOrder = 3
    object MemoComment: TMemo
      Left = 16
      Top = 24
      Width = 337
      Height = 94
      ReadOnly = True
      TabOrder = 0
    end
  end
  object GroupBoxAddress: TGroupBox
    Left = 242
    Top = 351
    Width = 386
    Height = 138
    Caption = #1040#1076#1088#1077#1089#1072
    TabOrder = 4
    object MemoAddress: TMemo
      Left = 16
      Top = 25
      Width = 353
      Height = 97
      TabOrder = 0
    end
  end
  object GroupBoxCustomer: TGroupBox
    Left = 11
    Top = 159
    Width = 225
    Height = 186
    Caption = #1047#1072#1084#1086#1074#1085#1080#1082
    TabOrder = 5
    object LabeledEditCustomerName: TLabeledEdit
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
    object LabeledEditCustomerPhone: TLabeledEdit
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
    object LabeledEditCustomerBalance: TLabeledEdit
      Left = 20
      Top = 143
      Width = 177
      Height = 23
      EditLabel.Width = 39
      EditLabel.Height = 15
      EditLabel.Caption = #1041#1072#1083#1072#1085#1089
      ReadOnly = True
      TabOrder = 2
      Text = ''
    end
  end
  object ButtonAddProduct: TButton
    Left = 634
    Top = 358
    Width = 210
    Height = 27
    Caption = #1044#1086#1076#1072#1090#1080' '#1090#1086#1074#1072#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    StyleElements = [seFont, seBorder]
    OnClick = ButtonAddProductClick
  end
  object ButtonDelProduct: TButton
    Left = 634
    Top = 391
    Width = 210
    Height = 26
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1090#1086#1074#1072#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    StyleElements = [seFont, seBorder]
    OnClick = ButtonDelProductClick
  end
  object GroupBoxInfo: TGroupBox
    Left = 11
    Top = 18
    Width = 456
    Height = 135
    Caption = #1030#1085#1092#1086#1088#1084#1072#1094#1110#1103
    TabOrder = 8
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
    object StartTimePicker: TDateTimePicker
      Left = 251
      Top = 95
      Width = 85
      Height = 23
      Date = 36892.000000000000000000
      Format = 'HH:mm'
      Time = 36892.000000000000000000
      Kind = dtkTime
      TabOrder = 1
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
      TabOrder = 2
    end
    object DatePicker: TDateTimePicker
      Left = 251
      Top = 45
      Width = 177
      Height = 23
      Date = 36892.000000000000000000
      Format = 'dd.MM.yyyy'
      Time = 36892.000000000000000000
      TabOrder = 3
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
      TabOrder = 4
      Text = ''
    end
  end
  object GroupBoxCallComment: TGroupBox
    Left = 11
    Top = 522
    Width = 617
    Height = 126
    Caption = #1050#1086#1084#1077#1085#1090#1072#1088' '#1076#1086' '#1076#1079#1074#1110#1085#1082#1091
    TabOrder = 9
    object MemoCallComment: TMemo
      Left = 15
      Top = 24
      Width = 585
      Height = 90
      TabOrder = 0
    end
  end
  object ComboBoxCallState: TComboBox
    Left = 643
    Top = 546
    Width = 201
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    Items.Strings = (
      #1044#1086#1087#1088#1072#1094#1100#1086#1074#1072#1085#1086' ('#1076#1086' '#1090#1077#1083#1077#1092#1086#1085#1110#1089#1090#1110#1074')'
      #1044#1086#1087#1088#1072#1094#1100#1086#1074#1072#1085#1086' ('#1076#1086' '#1092#1083#1086#1088#1080#1089#1090#1110#1074')')
  end
  object ButtonConfirm: TButton
    Left = 643
    Top = 612
    Width = 201
    Height = 36
    Caption = #1055#1110#1076#1090#1074#1077#1088#1076#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    StyleElements = [seFont, seBorder]
    OnClick = ButtonConfirmClick
  end
end
