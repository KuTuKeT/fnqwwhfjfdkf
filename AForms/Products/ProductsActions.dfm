object FormProductsActions: TFormProductsActions
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
  object LabelChoiceGroup: TLabel
    Left = 16
    Top = 23
    Width = 32
    Height = 15
    Caption = #1043#1088#1091#1087#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object ComboBoxChoiceGroup: TComboBox
    Left = 16
    Top = 44
    Width = 168
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object LabeledEditName: TLabeledEdit
    Left = 16
    Top = 96
    Width = 168
    Height = 23
    EditLabel.Width = 32
    EditLabel.Height = 15
    EditLabel.Caption = #1053#1072#1079#1074#1072
    TabOrder = 1
    Text = ''
  end
  object LabeledEditPrice: TLabeledEdit
    Left = 16
    Top = 146
    Width = 168
    Height = 23
    EditLabel.Width = 25
    EditLabel.Height = 15
    EditLabel.Caption = #1062#1110#1085#1072
    TabOrder = 2
    Text = ''
  end
  object ButtonAction: TButton
    Left = 16
    Top = 193
    Width = 168
    Height = 25
    TabOrder = 3
    OnClick = ButtonActionClick
  end
  object ButtonCancel: TButton
    Left = 16
    Top = 224
    Width = 168
    Height = 25
    Caption = #1057#1082#1072#1089#1091#1074#1072#1085#1085#1103
    TabOrder = 4
    OnClick = ButtonCancelClick
  end
end
