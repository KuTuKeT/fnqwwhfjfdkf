object FormNotes: TFormNotes
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1041#1083#1086#1085#1086#1090
  ClientHeight = 460
  ClientWidth = 609
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnShow = FormShow
  TextHeight = 15
  object LabelNote: TLabel
    Left = 14
    Top = 15
    Width = 199
    Height = 21
    Caption = #1047#1072#1084#1110#1090#1082#1080' '#1076#1086' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Montserrat'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ButtonConfirm: TButton
    Left = 14
    Top = 417
    Width = 581
    Height = 27
    Caption = #1042#1110#1076#1088#1072#1074#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = ButtonConfirmClick
  end
  object MemoText: TMemo
    Left = 14
    Top = 322
    Width = 581
    Height = 89
    Color = clScrollBar
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Montserrat'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object RichEditNotes: TRichEdit
    Left = 14
    Top = 42
    Width = 581
    Height = 274
    Color = clScrollBar
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Montserrat'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
end
