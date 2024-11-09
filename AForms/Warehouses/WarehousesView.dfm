object FormWarehousesView: TFormWarehousesView
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1057#1082#1083#1072#1076#1080
  ClientHeight = 381
  ClientWidth = 573
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
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
  object ListViewItems: TListView
    Left = 19
    Top = 55
    Width = 535
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
      end
      item
        Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100
        Width = 65
      end>
    TabOrder = 0
    ViewStyle = vsReport
    OnDblClick = ListViewItemsDblClick
  end
  object ComboBoxChoiceOffice: TComboBox
    Left = 61
    Top = 21
    Width = 193
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnChange = ComboBoxChoiceOfficeChange
  end
  object ButtonAdd: TButton
    Left = 19
    Top = 335
    Width = 260
    Height = 25
    Caption = #1044#1086#1076#1072#1090#1080' '#1090#1086#1074#1072#1088
    TabOrder = 2
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 294
    Top = 335
    Width = 260
    Height = 25
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1090#1086#1074#1072#1088
    TabOrder = 3
    OnClick = ButtonDelClick
  end
end
