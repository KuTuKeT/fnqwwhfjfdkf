object FormEmployeesView: TFormEmployeesView
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1057#1087#1110#1074#1088#1086#1073#1110#1090#1085#1080#1082#1080
  ClientHeight = 419
  ClientWidth = 382
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object LabelCount: TLabel
    Left = 16
    Top = 24
    Width = 201
    Height = 15
    Caption = #1047#1072#1075#1072#1083#1100#1085#1072' '#1082#1110#1083#1100#1082#1110#1089#1090#1100' '#1089#1087#1110#1074#1088#1086#1073#1110#1090#1085#1080#1082#1110#1074' - 0'
  end
  object LabelChoiceRole: TLabel
    Left = 16
    Top = 67
    Width = 35
    Height = 15
    Caption = #1056#1086#1083#1100' -'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object ComboBoxChoiceRole: TComboBox
    Left = 56
    Top = 63
    Width = 168
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnChange = ComboBoxChoiceRoleChange
  end
  object ListViewItems: TListView
    Left = 16
    Top = 96
    Width = 350
    Height = 267
    Columns = <
      item
        Caption = 'ID'
        Width = 55
      end
      item
        Caption = #1030#1084#39#1103' '#1055#1088#1110#1079#1074#1080#1097#1077
        Width = 150
      end
      item
        Caption = #1056#1086#1083#1100
        Width = 120
      end>
    TabOrder = 1
    ViewStyle = vsReport
    OnDblClick = ListViewItemsDblClick
  end
  object ButtonAdd: TButton
    Left = 16
    Top = 376
    Width = 170
    Height = 25
    Caption = #1044#1086#1076#1072#1090#1080' '#1089#1087#1110#1074#1088#1086#1073#1110#1090#1085#1080#1082#1072
    TabOrder = 2
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 196
    Top = 376
    Width = 170
    Height = 25
    Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1089#1087#1110#1074#1088#1086#1073#1110#1090#1085#1080#1082#1072
    TabOrder = 3
    OnClick = ButtonDelClick
  end
end
