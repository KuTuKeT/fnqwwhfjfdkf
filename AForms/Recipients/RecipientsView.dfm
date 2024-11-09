object FormRecipientsView: TFormRecipientsView
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095#1110
  ClientHeight = 349
  ClientWidth = 376
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
    Width = 335
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
      end>
    TabOrder = 0
    ViewStyle = vsReport
    OnDblClick = ListViewItemsDblClick
  end
  object ButtonAdd: TButton
    Left = 20
    Top = 304
    Width = 160
    Height = 25
    Caption = #1044#1086#1076#1072#1090#1080' '#1086#1090#1088#1080#1084#1091#1095#1074#1072#1095#1072
    TabOrder = 1
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 195
    Top = 304
    Width = 160
    Height = 25
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1086#1090#1088#1080#1084#1091#1074#1072#1095#1072
    TabOrder = 2
    OnClick = ButtonDelClick
  end
end
