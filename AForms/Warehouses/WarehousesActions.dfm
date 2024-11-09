object FormWarehousesActions: TFormWarehousesActions
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
  object LabelChoiceProduct: TLabel
    Left = 16
    Top = 26
    Width = 46
    Height = 15
    Caption = #1055#1088#1086#1076#1091#1082#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelChoiceOffice: TLabel
    Left = 16
    Top = 78
    Width = 27
    Height = 15
    Caption = #1054#1092#1110#1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabeledEditQuantity: TLabeledEdit
    Left = 16
    Top = 146
    Width = 168
    Height = 23
    EditLabel.Width = 49
    EditLabel.Height = 15
    EditLabel.Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100
    NumbersOnly = True
    TabOrder = 0
    Text = ''
  end
  object ButtonAction: TButton
    Left = 16
    Top = 193
    Width = 168
    Height = 25
    TabOrder = 1
    OnClick = ButtonActionClick
  end
  object ButtonCancel: TButton
    Left = 16
    Top = 224
    Width = 168
    Height = 25
    Caption = #1057#1082#1072#1089#1091#1074#1072#1085#1085#1103
    TabOrder = 2
    OnClick = ButtonCancelClick
  end
  object ComboBoxChoiceProduct: TComboBox
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
    TabOrder = 3
  end
  object ComboBoxChoiceOffice: TComboBox
    Left = 16
    Top = 96
    Width = 168
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
end
