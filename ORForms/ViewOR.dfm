object FormViewOR: TFormViewOR
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  ClientHeight = 641
  ClientWidth = 1095
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
    Left = 8
    Top = 362
    Width = 117
    Height = 15
    Caption = #1058#1086#1074#1072#1088#1080' '#1091' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1110':'
  end
  object LabelCalls: TLabel
    Left = 547
    Top = 362
    Width = 130
    Height = 15
    Caption = #1044#1079#1074#1110#1085#1082#1080' '#1076#1086' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103':'
  end
  object GroupBoxCustomer: TGroupBox
    Left = 239
    Top = 19
    Width = 225
    Height = 186
    Caption = #1047#1072#1084#1086#1074#1085#1080#1082
    TabOrder = 0
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
  object GroupBoxRecipient: TGroupBox
    Left = 239
    Top = 211
    Width = 225
    Height = 138
    Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095
    TabOrder = 1
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
  object ListViewProducts: TListView
    Left = 8
    Top = 383
    Width = 530
    Height = 241
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
    TabOrder = 2
    ViewStyle = vsReport
  end
  object ListViewCalls: TListView
    Left = 547
    Top = 383
    Width = 540
    Height = 241
    Columns = <
      item
        Caption = #8470
        Width = 35
      end
      item
        Caption = #1057#1090#1072#1090#1091#1089
        Width = 100
      end
      item
        Caption = #1057#1087#1110#1074#1088#1086#1073#1110#1090#1085#1080#1082
        Width = 150
      end
      item
        Caption = #1050#1086#1084#1077#1085#1090#1072#1088
        Width = 250
      end>
    TabOrder = 3
    ViewStyle = vsReport
  end
  object ButtonNotes: TButton
    Left = 8
    Top = 211
    Width = 225
    Height = 45
    Caption = #1047#1072#1084#1110#1090#1082#1080' '#1076#1086' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    StyleElements = [seFont, seBorder]
    OnClick = ButtonNotesClick
  end
  object GroupBoxInfo: TGroupBox
    Left = 8
    Top = 19
    Width = 225
    Height = 186
    Caption = #1030#1085#1092#1086#1088#1084#1072#1094#1110#1103
    TabOrder = 5
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
  object GroupBoxComment: TGroupBox
    Left = 470
    Top = 19
    Width = 617
    Height = 186
    Caption = #1050#1086#1084#1077#1085#1090#1072#1088
    TabOrder = 6
    object MemoComment: TMemo
      Left = 16
      Top = 24
      Width = 585
      Height = 149
      ReadOnly = True
      TabOrder = 0
    end
  end
  object GroupBoxAddress: TGroupBox
    Left = 470
    Top = 211
    Width = 617
    Height = 138
    Caption = #1040#1076#1088#1077#1089#1072
    TabOrder = 7
    object MemoAddress: TMemo
      Left = 16
      Top = 24
      Width = 585
      Height = 101
      ReadOnly = True
      TabOrder = 0
    end
  end
end
