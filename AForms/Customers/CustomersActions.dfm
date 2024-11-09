object FormCustomersActions: TFormCustomersActions
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 271
  ClientWidth = 204
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object ButtonAction: TButton
    Left = 18
    Top = 193
    Width = 168
    Height = 25
    TabOrder = 0
    OnClick = ButtonActionClick
  end
  object ButtonCancel: TButton
    Left = 18
    Top = 224
    Width = 168
    Height = 25
    Caption = #1057#1082#1072#1089#1091#1074#1072#1085#1085#1103
    TabOrder = 1
    OnClick = ButtonCancelClick
  end
  object LabeledEditName: TLabeledEdit
    Left = 18
    Top = 45
    Width = 168
    Height = 23
    EditLabel.Width = 21
    EditLabel.Height = 15
    EditLabel.Caption = #1030#1084#39#1103
    TabOrder = 2
    Text = ''
  end
  object LabeledEditBalance: TLabeledEdit
    Left = 18
    Top = 144
    Width = 168
    Height = 23
    EditLabel.Width = 39
    EditLabel.Height = 15
    EditLabel.Caption = #1041#1072#1083#1072#1085#1089
    TabOrder = 3
    Text = ''
  end
  object LabeledEditPhone: TLabeledEdit
    Left = 18
    Top = 96
    Width = 168
    Height = 23
    EditLabel.Width = 48
    EditLabel.Height = 15
    EditLabel.Caption = #1058#1077#1083#1077#1092#1086#1085
    NumbersOnly = True
    TabOrder = 4
    Text = ''
  end
end
