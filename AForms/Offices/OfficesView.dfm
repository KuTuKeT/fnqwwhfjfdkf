object FormOfficesView: TFormOfficesView
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1054#1092#1110#1089#1080
  ClientHeight = 349
  ClientWidth = 325
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object ListViewItems: TListView
    Left = 20
    Top = 24
    Width = 285
    Height = 267
    Columns = <
      item
        Caption = 'ID'
        Width = 55
      end
      item
        Caption = #1053#1072#1079#1074#1072
        Width = 200
      end>
    TabOrder = 0
    ViewStyle = vsReport
    OnDblClick = ListViewItemsDblClick
  end
  object ButtonAdd: TButton
    Left = 20
    Top = 304
    Width = 140
    Height = 25
    Caption = #1044#1086#1076#1072#1090#1080' '#1086#1092#1080#1089
    TabOrder = 1
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 165
    Top = 304
    Width = 140
    Height = 25
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1086#1092#1110#1089
    TabOrder = 2
    OnClick = ButtonDelClick
  end
end
