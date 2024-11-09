object FormLogin: TFormLogin
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1040#1074#1090#1086#1088#1080#1079#1072#1094#1110#1103
  ClientHeight = 166
  ClientWidth = 243
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object LabeledEditLogin: TLabeledEdit
    Left = 25
    Top = 33
    Width = 193
    Height = 23
    EditLabel.Width = 33
    EditLabel.Height = 15
    EditLabel.Caption = #1051#1086#1075#1110#1085':'
    TabOrder = 0
    Text = ''
  end
  object LabeledEditPass: TLabeledEdit
    Left = 25
    Top = 81
    Width = 193
    Height = 23
    EditLabel.Width = 45
    EditLabel.Height = 15
    EditLabel.Caption = #1055#1072#1088#1086#1083#1100':'
    PasswordChar = '*'
    TabOrder = 1
    Text = ''
  end
  object ButtonEnter: TButton
    Left = 25
    Top = 124
    Width = 160
    Height = 25
    Caption = #1042#1093#1110#1076
    TabOrder = 2
    OnClick = ButtonEnterClick
  end
end
