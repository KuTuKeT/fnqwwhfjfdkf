object FormEmployeesActions: TFormEmployeesActions
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 185
  ClientWidth = 374
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object LabelChoiceRole: TLabel
    Left = 16
    Top = 26
    Width = 27
    Height = 15
    Caption = #1056#1086#1083#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object ButtonAction: TButton
    Left = 16
    Top = 137
    Width = 168
    Height = 25
    TabOrder = 0
    OnClick = ButtonActionClick
  end
  object ButtonCancel: TButton
    Left = 190
    Top = 137
    Width = 168
    Height = 25
    Caption = #1057#1082#1072#1089#1091#1074#1072#1085#1085#1103
    TabOrder = 1
    OnClick = ButtonCancelClick
  end
  object LabeledEditName: TLabeledEdit
    Left = 16
    Top = 96
    Width = 168
    Height = 23
    EditLabel.Width = 21
    EditLabel.Height = 15
    EditLabel.Caption = #1030#1084#39#1103
    TabOrder = 2
    Text = ''
  end
  object LabeledEditPass: TLabeledEdit
    Left = 190
    Top = 96
    Width = 168
    Height = 23
    EditLabel.Width = 42
    EditLabel.Height = 15
    EditLabel.Caption = #1055#1072#1088#1086#1083#1100
    TabOrder = 3
    Text = ''
  end
  object LabeledEditLogin: TLabeledEdit
    Left = 190
    Top = 44
    Width = 168
    Height = 23
    EditLabel.Width = 30
    EditLabel.Height = 15
    EditLabel.Caption = #1051#1086#1075#1110#1085
    TabOrder = 4
    Text = ''
  end
  object ComboBoxChoiceRole: TComboBox
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
    TabOrder = 5
  end
end
