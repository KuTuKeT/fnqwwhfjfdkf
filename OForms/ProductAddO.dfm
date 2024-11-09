object FormProductAddO: TFormProductAddO
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1044#1086#1076#1072#1074#1072#1085#1085#1103
  ClientHeight = 376
  ClientWidth = 573
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnShow = FormShow
  TextHeight = 15
  object LabelChoiceOffice: TLabel
    Left = 19
    Top = 25
    Width = 38
    Height = 15
    Caption = #1054#1092#1110#1089' - '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabeledEditQuantity: TLabeledEdit
    Left = 202
    Top = 300
    Width = 168
    Height = 23
    EditLabel.Width = 49
    EditLabel.Height = 15
    EditLabel.Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100
    NumbersOnly = True
    TabOrder = 0
    Text = ''
  end
  object LabeledEditPrice: TLabeledEdit
    Left = 19
    Top = 300
    Width = 168
    Height = 23
    EditLabel.Width = 25
    EditLabel.Height = 15
    EditLabel.Caption = #1062#1110#1085#1072
    NumbersOnly = True
    TabOrder = 1
    Text = ''
  end
  object ButtonAdd: TButton
    Left = 19
    Top = 329
    Width = 168
    Height = 25
    Caption = #1044#1086#1076#1072#1090#1080
    TabOrder = 2
    OnClick = ButtonAddClick
  end
  object ButtonCancel: TButton
    Left = 202
    Top = 329
    Width = 168
    Height = 25
    Caption = #1057#1082#1072#1089#1091#1074#1072#1085#1085#1103
    TabOrder = 3
    OnClick = ButtonCancelClick
  end
  object ListViewItems: TListView
    Left = 19
    Top = 55
    Width = 535
    Height = 210
    Columns = <
      item
        Caption = #1053#1086#1084#1077#1088
        Width = 55
      end
      item
        Caption = #1053#1072#1079#1074#1072
        Width = 200
      end
      item
        Caption = #1043#1088#1091#1087#1072
        Width = 120
      end
      item
        Caption = #1062#1110#1085#1072
        Width = 70
      end
      item
        Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100
        Width = 65
      end>
    TabOrder = 4
    ViewStyle = vsReport
    OnClick = ListViewItemsClick
  end
end
