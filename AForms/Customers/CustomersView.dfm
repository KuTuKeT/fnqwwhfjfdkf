object FormCustomersView: TFormCustomersView
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1047#1072#1084#1086#1074#1085#1080#1082#1080
  ClientHeight = 349
  ClientWidth = 437
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object ButtonAdd: TButton
    Left = 18
    Top = 304
    Width = 190
    Height = 25
    Caption = #1044#1086#1076#1072#1090#1080' '#1079#1072#1084#1086#1074#1085#1080#1082#1072
    TabOrder = 0
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 228
    Top = 304
    Width = 190
    Height = 25
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1079#1072#1084#1086#1074#1085#1080#1082#1072
    TabOrder = 1
    OnClick = ButtonDelClick
  end
  object ListViewItems: TListView
    Left = 18
    Top = 24
    Width = 400
    Height = 267
    Columns = <
      item
        Caption = 'ID'
        Width = 55
      end
      item
        Caption = #1030#1084#39#1103
        Width = 150
      end
      item
        Caption = #1058#1077#1083#1077#1092#1086#1085
        Width = 100
      end
      item
        Caption = #1041#1072#1083#1072#1085#1089
        Width = 70
      end>
    TabOrder = 2
    ViewStyle = vsReport
    OnDblClick = ListViewItemsDblClick
  end
end
