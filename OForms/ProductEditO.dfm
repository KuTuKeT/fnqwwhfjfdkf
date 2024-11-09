object FormProductEditO: TFormProductEditO
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103
  ClientHeight = 222
  ClientWidth = 204
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
    Top = 145
    Width = 168
    Height = 25
    Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1090#1080
    TabOrder = 0
    OnClick = ButtonAddClick
  end
  object ButtonCancel: TButton
    Left = 18
    Top = 176
    Width = 168
    Height = 25
    Caption = #1057#1082#1072#1089#1091#1074#1072#1085#1085#1103
    TabOrder = 1
    OnClick = ButtonCancelClick
  end
  object LabeledEditQuantity: TLabeledEdit
    Left = 18
    Top = 96
    Width = 168
    Height = 23
    EditLabel.Width = 49
    EditLabel.Height = 15
    EditLabel.Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100
    NumbersOnly = True
    TabOrder = 2
    Text = ''
  end
  object LabeledEditPrice: TLabeledEdit
    Left = 18
    Top = 45
    Width = 168
    Height = 23
    EditLabel.Width = 25
    EditLabel.Height = 15
    EditLabel.Caption = #1062#1110#1085#1072
    TabOrder = 3
    Text = ''
  end
end
