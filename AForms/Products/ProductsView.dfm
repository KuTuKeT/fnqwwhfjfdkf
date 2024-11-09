object FormProductsView: TFormProductsView
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1058#1086#1074#1072#1088#1080
  ClientHeight = 379
  ClientWidth = 509
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object LabelChoiceGroup: TLabel
    Left = 19
    Top = 26
    Width = 87
    Height = 15
    Caption = #1043#1088#1091#1087#1087#1072' '#1090#1086#1074#1072#1088#1091' -'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object ComboBoxChoiceGroup: TComboBox
    Left = 112
    Top = 22
    Width = 193
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnChange = ComboBoxChoiceGroupChange
  end
  object ListViewItems: TListView
    Left = 19
    Top = 56
    Width = 470
    Height = 267
    Columns = <
      item
        Caption = 'ID'
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
      end>
    TabOrder = 1
    ViewStyle = vsReport
    OnDblClick = ListViewItemsDblClick
  end
  object ButtonAdd: TButton
    Left = 19
    Top = 336
    Width = 230
    Height = 25
    Caption = #1044#1086#1076#1072#1090#1080' '#1090#1086#1074#1072#1088
    TabOrder = 2
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 259
    Top = 336
    Width = 230
    Height = 25
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1090#1086#1074#1072#1088
    TabOrder = 3
    OnClick = ButtonDelClick
  end
end
