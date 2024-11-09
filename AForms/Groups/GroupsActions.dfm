object FormGroupsActions: TFormGroupsActions
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 161
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
    Top = 89
    Width = 168
    Height = 25
    TabOrder = 0
    OnClick = ButtonActionClick
  end
  object ButtonCancel: TButton
    Left = 18
    Top = 120
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
    EditLabel.Width = 32
    EditLabel.Height = 15
    EditLabel.Caption = #1053#1072#1079#1074#1072
    TabOrder = 2
    Text = ''
  end
end
