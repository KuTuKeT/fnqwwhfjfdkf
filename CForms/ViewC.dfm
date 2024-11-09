object FormViewC: TFormViewC
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  ClientHeight = 578
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
  object LabelProducts: TLabel
    Left = 240
    Top = 173
    Width = 117
    Height = 15
    Caption = #1058#1086#1074#1072#1088#1080' '#1091' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1110':'
  end
  object LabeCallState: TLabel
    Left = 568
    Top = 450
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
  object Bevel_1: TBevel
    Left = 9
    Top = 418
    Width = 761
    Height = 15
    Shape = bsTopLine
  end
  object ButtonNotes: TButton
    Left = 9
    Top = 354
    Width = 225
    Height = 45
    Caption = #1047#1072#1084#1110#1090#1082#1080' '#1076#1086' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    StyleElements = [seFont, seBorder]
    OnClick = ButtonNotesClick
  end
  object GroupBoxRecipient: TGroupBox
    Left = 9
    Top = 210
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
  object GroupBoxAddress: TGroupBox
    Left = 240
    Top = 24
    Width = 529
    Height = 135
    Caption = #1040#1076#1088#1077#1089#1072
    TabOrder = 2
    object MemoAddress: TMemo
      Left = 16
      Top = 24
      Width = 497
      Height = 94
      ReadOnly = True
      TabOrder = 0
    end
  end
  object ListViewProducts: TListView
    Left = 240
    Top = 194
    Width = 530
    Height = 205
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
    TabOrder = 3
    ViewStyle = vsReport
  end
  object ComboBoxCallState: TComboBox
    Left = 568
    Top = 471
    Width = 201
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    Items.Strings = (
      #1044#1086#1089#1090#1072#1074#1083#1077#1085#1086
      #1053#1077' '#1076#1086#1089#1090#1072#1074#1083#1077#1085#1086)
  end
  object ButtonConfirm: TButton
    Left = 569
    Top = 529
    Width = 201
    Height = 36
    Caption = #1055#1110#1076#1090#1074#1077#1088#1076#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    StyleElements = [seFont, seBorder]
    OnClick = ButtonConfirmClick
  end
  object GroupBoxCallComment: TGroupBox
    Left = 9
    Top = 439
    Width = 553
    Height = 126
    Caption = #1050#1086#1084#1077#1085#1090#1072#1088' '#1076#1086' '#1076#1079#1074#1110#1085#1082#1091
    TabOrder = 6
    object MemoCallComment: TMemo
      Left = 14
      Top = 24
      Width = 523
      Height = 90
      TabOrder = 0
    end
  end
  object GroupBoxInfo: TGroupBox
    Left = 9
    Top = 18
    Width = 225
    Height = 186
    Caption = #1030#1085#1092#1086#1088#1084#1072#1094#1110#1103
    TabOrder = 7
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
end
