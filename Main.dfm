object FormMain: TFormMain
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1052#1077#1085#1102' '#1088#1086#1073#1086#1090#1080
  ClientHeight = 672
  ClientWidth = 1109
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnShow = FormShow
  TextHeight = 15
  object LabelUser: TLabel
    Left = 22
    Top = 24
    Width = 198
    Height = 15
    Caption = #1057#1087#1110#1074#1088#1086#1073#1110#1090#1085#1080#1082' - '#1052#1077#1097#1077#1088#1089#1100#1082#1080#1093' '#1042#1072#1089#1080#1083#1100
  end
  object LabelRole: TLabel
    Left = 22
    Top = 45
    Width = 117
    Height = 15
    Caption = #1056#1086#1083#1100' - '#1040#1076#1084#1110#1085#1110#1089#1090#1088#1072#1090#1086#1088
  end
  object PageControl: TPageControl
    Left = 8
    Top = 84
    Width = 1098
    Height = 580
    ActivePage = TabSheetO
    TabOrder = 0
    OnChange = PageControlChange
    object TabSheetOR: TTabSheet
      Caption = #1047#1072#1084#1086#1074#1083#1077#1085#1085#1103
      ImageIndex = 5
      object Bevel_1OR: TBevel
        AlignWithMargins = True
        Left = 25
        Top = 179
        Width = 1041
        Height = 17
        Shape = bsTopLine
      end
      object GroupBoxFitersOR: TGroupBox
        Left = 13
        Top = 14
        Width = 649
        Height = 146
        Caption = #1060#1110#1083#1100#1090#1088#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object LabelChoiceTime_1OR: TLabel
          Left = 15
          Top = 110
          Width = 83
          Height = 15
          Caption = #1063#1072#1089' '#1076#1086#1089#1090#1072#1074#1082#1080' '#1079' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceTime_2OR: TLabel
          Left = 172
          Top = 110
          Width = 13
          Height = 15
          Caption = #1076#1086
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabeOrderStateOR: TLabel
          Left = 273
          Top = 84
          Width = 105
          Height = 15
          Caption = #1057#1090#1072#1090#1091#1089' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceDate_2OR: TLabel
          Left = 172
          Top = 52
          Width = 13
          Height = 15
          Caption = #1076#1086
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceDate_1OR: TLabel
          Left = 15
          Top = 52
          Width = 88
          Height = 15
          Caption = #1044#1072#1090#1072' '#1076#1086#1089#1090#1072#1074#1082#1080' '#1079' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceOfficeOR: TLabel
          Left = 273
          Top = 28
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
        object DateTimePicker_4OR: TDateTimePicker
          Left = 191
          Top = 106
          Width = 57
          Height = 23
          Date = 45570.000000000000000000
          Format = 'HH:mm'
          Time = 0.999305555553291900
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          Kind = dtkTime
          ParentFont = False
          TabOrder = 0
        end
        object DateTimePicker_3OR: TDateTimePicker
          Left = 109
          Top = 106
          Width = 57
          Height = 23
          Date = 45571.000000000000000000
          Format = 'HH:mm'
          Time = 45571.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          Kind = dtkTime
          ParentFont = False
          TabOrder = 1
        end
        object ComboBoxChoiceOfficeOR: TComboBox
          Left = 273
          Top = 49
          Width = 168
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
        object DateTimePicker_2OR: TDateTimePicker
          Left = 191
          Top = 49
          Width = 57
          Height = 23
          Date = 36892.000000000000000000
          Format = 'dd.MM'
          Time = 36892.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
        end
        object DateTimePicker_1OR: TDateTimePicker
          Left = 109
          Top = 49
          Width = 57
          Height = 23
          Date = 36892.000000000000000000
          Format = 'dd.MM'
          Time = 36892.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
        end
        object ButtonClearOR: TButton
          Left = 465
          Top = 104
          Width = 168
          Height = 25
          Caption = #1054#1095#1080#1089#1090#1080#1090#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          StyleElements = [seFont, seBorder]
          OnClick = ButtonClearClick
        end
        object ComboBoxOrderStateOR: TComboBox
          Left = 273
          Top = 105
          Width = 168
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          Text = #1059#1089#1110
          Items.Strings = (
            #1059#1089#1110
            #1053#1072' '#1076#1086#1087#1088#1072#1094#1102#1074#1072#1085#1085#1110
            #1059' '#1090#1077#1083#1077#1092#1086#1085#1110#1111
            #1047#1073#1080#1088#1072#1108#1090#1100#1089#1103
            #1053#1072' '#1076#1086#1089#1090#1072#1074#1094#1110
            #1042#1080#1082#1086#1085#1072#1085#1077)
        end
      end
      object GroupBoxSearchOR: TGroupBox
        Left = 668
        Top = 14
        Width = 410
        Height = 146
        Caption = #1055#1086#1096#1091#1082
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object LabelSearchChoiceOR: TLabel
          Left = 16
          Top = 84
          Width = 83
          Height = 15
          Caption = #1060#1110#1083#1100#1090#1088' '#1087#1086#1096#1091#1082#1091
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelSearchOR: TLabel
          Left = 16
          Top = 28
          Width = 53
          Height = 15
          Caption = #1047#1085#1072#1095#1077#1085#1085#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object ButtonConfirmOR: TButton
          Left = 216
          Top = 104
          Width = 178
          Height = 25
          Caption = #1057#1092#1086#1088#1084#1091#1074#1072#1090#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          StyleElements = [seFont, seBorder]
          OnClick = ButtonConfirmClick
        end
        object EditSearchOR: TEdit
          Left = 16
          Top = 49
          Width = 375
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          MaxLength = 255
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          TextHint = #1042#1074#1077#1076#1110#1090#1100' '#1079#1085#1072#1095#1077#1085#1085#1103
        end
        object ComboBoxSearchOR: TComboBox
          Left = 16
          Top = 105
          Width = 168
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = #1042#1110#1076#1089#1091#1090#1085#1110#1081
          Items.Strings = (
            #1042#1110#1076#1089#1091#1090#1085#1110#1081
            'ID '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            #1058#1077#1083'. '#1079#1072#1084#1086#1074#1085#1080#1082#1072
            #1058#1077#1083'. '#1086#1090#1088#1080#1084#1091#1074#1072#1095#1072)
        end
      end
      object ListViewOrdersOR: TListView
        Left = 3
        Top = 199
        Width = 578
        Height = 338
        Columns = <
          item
            Caption = #8470
            Width = 55
          end
          item
            Caption = #1044#1072#1090#1072' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 110
          end
          item
            Caption = #1063#1072#1089
            Width = 100
          end
          item
            Caption = #1054#1092#1110#1089
            Width = 160
          end
          item
            Caption = #1057#1090#1072#1090#1091#1089' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 145
          end>
        TabOrder = 2
        ViewStyle = vsReport
        OnClick = ListViewClick
        OnDblClick = ListViewDblClick
      end
      object ListViewProductsOR: TListView
        Left = 587
        Top = 199
        Width = 500
        Height = 338
        Columns = <
          item
            Caption = #1053#1072#1081#1084#1077#1085#1091#1074#1072#1085#1085#1103
            Width = 205
          end
          item
            Caption = #1043#1088#1091#1087#1087#1072
            Width = 160
          end
          item
            Caption = #1062#1110#1085#1072
            Width = 65
          end
          item
            Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100
            Width = 65
          end>
        TabOrder = 3
        ViewStyle = vsReport
        OnDblClick = ListViewDblClick
      end
    end
    object TabSheetO: TTabSheet
      Caption = #1054#1087#1077#1088#1072#1090#1086#1088
      ImageIndex = 1
      TabVisible = False
      object Bevel_1O: TBevel
        Left = 25
        Top = 179
        Width = 1041
        Height = 17
        Shape = bsTopLine
      end
      object GroupBoxFitersO: TGroupBox
        Left = 13
        Top = 14
        Width = 460
        Height = 146
        Caption = #1060#1110#1083#1100#1090#1088#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object LabelChoiceTime_1O: TLabel
          Left = 15
          Top = 110
          Width = 83
          Height = 15
          Caption = #1063#1072#1089' '#1076#1086#1089#1090#1072#1074#1082#1080' '#1079' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceTime_2O: TLabel
          Left = 172
          Top = 110
          Width = 13
          Height = 15
          Caption = #1076#1086
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabeCallStateO: TLabel
          Left = 273
          Top = 28
          Width = 78
          Height = 15
          Caption = #1057#1090#1072#1090#1091#1089' '#1076#1079#1074#1110#1085#1082#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceDate_2O: TLabel
          Left = 172
          Top = 52
          Width = 13
          Height = 15
          Caption = #1076#1086
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceDate_1O: TLabel
          Left = 15
          Top = 52
          Width = 88
          Height = 15
          Caption = #1044#1072#1090#1072' '#1076#1086#1089#1090#1072#1074#1082#1080' '#1079' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object DateTimePicker_4O: TDateTimePicker
          Left = 191
          Top = 106
          Width = 57
          Height = 23
          Date = 45570.000000000000000000
          Format = 'HH:mm'
          Time = 0.999305555553291900
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          Kind = dtkTime
          ParentFont = False
          TabOrder = 0
        end
        object DateTimePicker_3O: TDateTimePicker
          Left = 109
          Top = 106
          Width = 57
          Height = 23
          Date = 45571.000000000000000000
          Format = 'HH:mm'
          Time = 45571.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          Kind = dtkTime
          ParentFont = False
          TabOrder = 1
        end
        object ComboBoxCallStateO: TComboBox
          Left = 273
          Top = 49
          Width = 168
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = #1059#1089#1110
          Items.Strings = (
            #1059#1089#1110
            #1053#1086#1074#1080#1081
            #1042' '#1088#1086#1073#1086#1090#1110
            #1047#1072#1082#1088#1080#1090#1080#1081)
        end
        object DateTimePicker_2O: TDateTimePicker
          Left = 191
          Top = 49
          Width = 57
          Height = 23
          Date = 36892.000000000000000000
          Format = 'dd.MM'
          Time = 36892.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
        end
        object DateTimePicker_1O: TDateTimePicker
          Left = 109
          Top = 49
          Width = 57
          Height = 23
          Date = 36892.000000000000000000
          Format = 'dd.MM'
          Time = 36892.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
        end
        object ButtonClearO: TButton
          Left = 273
          Top = 104
          Width = 168
          Height = 25
          Caption = #1054#1095#1080#1089#1090#1080#1090#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          StyleElements = [seFont, seBorder]
          OnClick = ButtonClearClick
        end
      end
      object GroupBoxSearchO: TGroupBox
        Left = 482
        Top = 14
        Width = 415
        Height = 146
        Caption = #1055#1086#1096#1091#1082
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object LabelSearchChoiceO: TLabel
          Left = 16
          Top = 84
          Width = 83
          Height = 15
          Caption = #1060#1110#1083#1100#1090#1088' '#1087#1086#1096#1091#1082#1091
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelSearchO: TLabel
          Left = 16
          Top = 28
          Width = 53
          Height = 15
          Caption = #1047#1085#1072#1095#1077#1085#1085#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object ButtonConfirmO: TButton
          Left = 216
          Top = 104
          Width = 178
          Height = 25
          Caption = #1057#1092#1086#1088#1084#1091#1074#1072#1090#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          StyleElements = [seFont, seBorder]
          OnClick = ButtonConfirmClick
        end
        object EditSearchO: TEdit
          Left = 16
          Top = 49
          Width = 375
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          MaxLength = 255
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          TextHint = #1042#1074#1077#1076#1110#1090#1100' '#1079#1085#1072#1095#1077#1085#1085#1103
        end
        object ComboBoxSearchO: TComboBox
          Left = 16
          Top = 105
          Width = 168
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = #1042#1110#1076#1089#1091#1090#1085#1110#1081
          Items.Strings = (
            #1042#1110#1076#1089#1091#1090#1085#1110#1081
            'ID '#1076#1079#1074#1110#1085#1082#1072
            'ID '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            #1054#1092#1110#1089)
        end
      end
      object ListViewCallsO: TListView
        Left = 3
        Top = 199
        Width = 1084
        Height = 338
        Columns = <
          item
            Caption = #8470
            Width = 55
          end
          item
            Caption = #8470' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 95
          end
          item
            Caption = #1044#1072#1090#1072' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 110
          end
          item
            Caption = #1063#1072#1089
            Width = 100
          end
          item
            Caption = #1054#1092#1110#1089
            Width = 120
          end
          item
            Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095
            Width = 250
          end
          item
            Caption = #1047#1072#1084#1086#1074#1085#1080#1082
            Width = 250
          end
          item
            Caption = #1057#1090#1072#1090#1091#1089' '#1076#1079#1074#1110#1085#1082#1072
            Width = 100
          end>
        TabOrder = 2
        ViewStyle = vsReport
        OnDblClick = ListViewDblClick
      end
    end
    object TabSheetT: TTabSheet
      Caption = #1058#1077#1083#1077#1092#1086#1085#1110#1089#1090
      TabVisible = False
      object Bevel_1T: TBevel
        Left = 25
        Top = 179
        Width = 1041
        Height = 17
        Shape = bsTopLine
      end
      object GroupBoxFitersT: TGroupBox
        Left = 13
        Top = 14
        Width = 460
        Height = 146
        Caption = #1060#1110#1083#1100#1090#1088#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object LabelChoiceTime_1T: TLabel
          Left = 15
          Top = 110
          Width = 83
          Height = 15
          Caption = #1063#1072#1089' '#1076#1086#1089#1090#1072#1074#1082#1080' '#1079' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceTime_2T: TLabel
          Left = 172
          Top = 110
          Width = 13
          Height = 15
          Caption = #1076#1086
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabeCallStateT: TLabel
          Left = 273
          Top = 28
          Width = 78
          Height = 15
          Caption = #1057#1090#1072#1090#1091#1089' '#1076#1079#1074#1110#1085#1082#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceDate_2T: TLabel
          Left = 172
          Top = 52
          Width = 13
          Height = 15
          Caption = #1076#1086
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelChoiceDate_1T: TLabel
          Left = 15
          Top = 52
          Width = 88
          Height = 15
          Caption = #1044#1072#1090#1072' '#1076#1086#1089#1090#1072#1074#1082#1080' '#1079' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object DateTimePicker_4T: TDateTimePicker
          Left = 191
          Top = 106
          Width = 57
          Height = 23
          Date = 45570.000000000000000000
          Format = 'HH:mm'
          Time = 0.999305555553291900
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          Kind = dtkTime
          ParentFont = False
          TabOrder = 0
        end
        object DateTimePicker_3T: TDateTimePicker
          Left = 109
          Top = 106
          Width = 57
          Height = 23
          Date = 45571.000000000000000000
          Format = 'HH:mm'
          Time = 45571.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          Kind = dtkTime
          ParentFont = False
          TabOrder = 1
        end
        object ComboBoxCallStateT: TComboBox
          Left = 273
          Top = 49
          Width = 168
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = #1059#1089#1110
          Items.Strings = (
            #1059#1089#1110
            #1053#1086#1074#1080#1081
            #1042' '#1088#1086#1073#1086#1090#1110
            #1047#1072#1082#1088#1080#1090#1080#1081)
        end
        object DateTimePicker_2T: TDateTimePicker
          Left = 191
          Top = 49
          Width = 57
          Height = 23
          Date = 36892.000000000000000000
          Format = 'dd.MM'
          Time = 36892.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
        end
        object DateTimePicker_1T: TDateTimePicker
          Left = 109
          Top = 49
          Width = 57
          Height = 23
          Date = 36892.000000000000000000
          Format = 'dd.MM'
          Time = 36892.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
        end
        object ButtonClearT: TButton
          Left = 273
          Top = 104
          Width = 168
          Height = 25
          Caption = #1054#1095#1080#1089#1090#1080#1090#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          StyleElements = [seFont, seBorder]
          OnClick = ButtonClearClick
        end
      end
      object GroupBoxSearchT: TGroupBox
        Left = 482
        Top = 14
        Width = 415
        Height = 146
        Caption = #1055#1086#1096#1091#1082
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object LabelSearchChoiceT: TLabel
          Left = 16
          Top = 84
          Width = 83
          Height = 15
          Caption = #1060#1110#1083#1100#1090#1088' '#1087#1086#1096#1091#1082#1091
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object LabelSearchT: TLabel
          Left = 16
          Top = 28
          Width = 53
          Height = 15
          Caption = #1047#1085#1072#1095#1077#1085#1085#1103
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
        end
        object ButtonConfirmT: TButton
          Left = 216
          Top = 104
          Width = 178
          Height = 25
          Caption = #1057#1092#1086#1088#1084#1091#1074#1072#1090#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          StyleElements = [seFont, seBorder]
          OnClick = ButtonConfirmClick
        end
        object EditSearchT: TEdit
          Left = 16
          Top = 49
          Width = 375
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          MaxLength = 255
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          TextHint = #1042#1074#1077#1076#1110#1090#1100' '#1079#1085#1072#1095#1077#1085#1085#1103
        end
        object ComboBoxSearchT: TComboBox
          Left = 16
          Top = 105
          Width = 168
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Text = #1042#1110#1076#1089#1091#1090#1085#1110#1081
          Items.Strings = (
            #1042#1110#1076#1089#1091#1090#1085#1110#1081
            'ID '#1076#1079#1074#1110#1085#1082#1072
            'ID '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            #1054#1092#1110#1089)
        end
      end
      object ListViewCallsT: TListView
        Left = 3
        Top = 199
        Width = 1084
        Height = 338
        Columns = <
          item
            Caption = #8470
            Width = 55
          end
          item
            Caption = #8470' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 95
          end
          item
            Caption = #1044#1072#1090#1072' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 110
          end
          item
            Caption = #1063#1072#1089
            Width = 100
          end
          item
            Caption = #1054#1092#1110#1089
            Width = 120
          end
          item
            Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095
            Width = 250
          end
          item
            Caption = #1047#1072#1084#1086#1074#1085#1080#1082
            Width = 250
          end
          item
            Caption = #1057#1090#1072#1090#1091#1089' '#1076#1079#1074#1110#1085#1082#1072
            Width = 100
          end>
        TabOrder = 2
        ViewStyle = vsReport
        OnDblClick = ListViewDblClick
      end
    end
    object TabSheetF: TTabSheet
      Caption = #1060#1083#1086#1088#1080#1089#1090
      ImageIndex = 2
      TabVisible = False
      object Bevel_1F: TBevel
        Left = 25
        Top = 61
        Width = 1041
        Height = 15
        Shape = bsTopLine
      end
      object LabelChoiceOfficeF: TLabel
        Left = 10
        Top = 21
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
      object LabelChoiceDate_2F: TLabel
        Left = 396
        Top = 21
        Width = 13
        Height = 15
        Caption = #1076#1086
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object LabelChoiceDate_1F: TLabel
        Left = 239
        Top = 21
        Width = 88
        Height = 15
        Caption = #1044#1072#1090#1072' '#1076#1086#1089#1090#1072#1074#1082#1080' '#1079' '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object LabelСallStateF: TLabel
        Left = 510
        Top = 21
        Width = 87
        Height = 15
        Caption = #1057#1090#1072#1090#1091#1089' '#1086#1073#1088#1086#1073#1082#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object ComboBoxChoiceOfficeF: TComboBox
        Left = 43
        Top = 18
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
      object ButtonConfirmF: TButton
        Left = 897
        Top = 17
        Width = 178
        Height = 25
        Caption = #1057#1092#1086#1088#1084#1091#1074#1072#1090#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        StyleElements = [seFont, seBorder]
        OnClick = ButtonConfirmClick
      end
      object DateTimePicker_1F: TDateTimePicker
        Left = 333
        Top = 18
        Width = 57
        Height = 23
        Date = 36892.000000000000000000
        Format = 'dd.MM'
        Time = 36892.000000000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object DateTimePicker_2F: TDateTimePicker
        Left = 415
        Top = 18
        Width = 57
        Height = 23
        Date = 36892.000000000000000000
        Format = 'dd.MM'
        Time = 36892.000000000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object ComboBoxCallStateF: TComboBox
        Left = 603
        Top = 18
        Width = 168
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ItemIndex = 0
        ParentFont = False
        TabOrder = 4
        Text = #1059#1089#1110
        Items.Strings = (
          #1059#1089#1110
          #1053#1086#1074#1080#1081
          #1042' '#1088#1086#1073#1086#1090#1110
          #1047#1072#1082#1088#1080#1090#1080#1081)
      end
      object ListViewCallsF: TListView
        Left = 3
        Top = 82
        Width = 615
        Height = 455
        Columns = <
          item
            Caption = #8470
            Width = 55
          end
          item
            Caption = #8470' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 95
          end
          item
            Caption = #1044#1072#1090#1072' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 110
          end
          item
            Caption = #1063#1072#1089
            Width = 100
          end
          item
            Caption = #1054#1092#1110#1089
            Width = 130
          end
          item
            Caption = #1057#1090#1072#1090#1091#1089' '#1086#1073#1088#1086#1073#1082#1080
            Width = 120
          end>
        TabOrder = 5
        ViewStyle = vsReport
        OnClick = ListViewClick
        OnDblClick = ListViewDblClick
      end
      object ListViewProductsF: TListView
        Left = 624
        Top = 82
        Width = 464
        Height = 455
        Columns = <
          item
            Caption = #1053#1072#1081#1084#1077#1085#1091#1074#1072#1085#1085#1103
            Width = 200
          end
          item
            Caption = #1043#1088#1091#1087#1087#1072
            Width = 130
          end
          item
            Caption = #1062#1110#1085#1072
            Width = 65
          end
          item
            Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100
            Width = 65
          end>
        TabOrder = 6
        ViewStyle = vsReport
      end
    end
    object TabSheetC: TTabSheet
      Caption = #1050#1091#1088#1100#1077#1088
      ImageIndex = 3
      TabVisible = False
      object LabelChoiceOfficeC: TLabel
        Left = 10
        Top = 21
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
      object Bevel_1C: TBevel
        Left = 25
        Top = 61
        Width = 1041
        Height = 15
        Shape = bsTopLine
      end
      object LabelChoiceDate_1C: TLabel
        Left = 239
        Top = 21
        Width = 88
        Height = 15
        Caption = #1044#1072#1090#1072' '#1076#1086#1089#1090#1072#1074#1082#1080' '#1079' '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object LabelChoiceDate_2C: TLabel
        Left = 396
        Top = 21
        Width = 13
        Height = 15
        Caption = #1076#1086
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object LabelСallStateC: TLabel
        Left = 510
        Top = 21
        Width = 87
        Height = 15
        Caption = #1057#1090#1072#1090#1091#1089' '#1086#1073#1088#1086#1073#1082#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
      end
      object ComboBoxChoiceOfficeC: TComboBox
        Left = 43
        Top = 18
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
      object ListViewCallsC: TListView
        Left = 3
        Top = 82
        Width = 1084
        Height = 455
        Columns = <
          item
            Caption = #8470
            Width = 55
          end
          item
            Caption = #8470' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 95
          end
          item
            Caption = #1044#1072#1090#1072' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
            Width = 110
          end
          item
            Caption = #1063#1072#1089
            Width = 80
          end
          item
            Caption = #1057#1090#1072#1090#1091#1089' '#1086#1073#1088#1086#1073#1082#1080
            Width = 120
          end
          item
            Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095
            Width = 200
          end
          item
            Caption = #1040#1076#1088#1077#1089#1072
            Width = 400
          end>
        TabOrder = 1
        ViewStyle = vsReport
        OnDblClick = ListViewDblClick
      end
      object ButtonConfirmC: TButton
        Left = 897
        Top = 17
        Width = 178
        Height = 25
        Caption = #1057#1092#1086#1088#1084#1091#1074#1072#1090#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        StyleElements = [seFont, seBorder]
        OnClick = ButtonConfirmClick
      end
      object DateTimePicker_1C: TDateTimePicker
        Left = 333
        Top = 18
        Width = 57
        Height = 23
        Date = 36892.000000000000000000
        Format = 'dd.MM'
        Time = 36892.000000000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object DateTimePicker_2C: TDateTimePicker
        Left = 415
        Top = 18
        Width = 57
        Height = 23
        Date = 36892.000000000000000000
        Format = 'dd.MM'
        Time = 36892.000000000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
      object ComboBoxCallStateC: TComboBox
        Left = 603
        Top = 18
        Width = 168
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ItemIndex = 0
        ParentFont = False
        TabOrder = 5
        Text = #1059#1089#1110
        Items.Strings = (
          #1059#1089#1110
          #1053#1086#1074#1080#1081
          #1042' '#1088#1086#1073#1086#1090#1110
          #1047#1072#1082#1088#1080#1090#1080#1081)
      end
    end
    object TabSheetA: TTabSheet
      Caption = #1040#1076#1084#1110#1085#1110#1089#1090#1088#1072#1090#1086#1088
      ImageIndex = 4
      TabVisible = False
      object GroupBoxUsers: TGroupBox
        Left = 13
        Top = 16
        Width = 215
        Height = 137
        Caption = #1059#1087#1088#1072#1074#1083#1110#1085#1085#1103' '#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072#1084#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object ButtonEmpls: TButton
          Left = 17
          Top = 32
          Width = 178
          Height = 25
          Caption = #1057#1087#1110#1074#1088#1086#1073#1110#1090#1085#1080#1082#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          StyleElements = [seFont, seBorder]
          OnClick = ButtonEmplsClick
        end
        object ButtonCustomers: TButton
          Left = 17
          Top = 63
          Width = 178
          Height = 25
          Caption = #1047#1072#1084#1086#1074#1085#1080#1082#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          StyleElements = [seFont, seBorder]
          OnClick = ButtonCustomersClick
        end
        object ButtonRecipients: TButton
          Left = 17
          Top = 94
          Width = 178
          Height = 25
          Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095#1110
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          StyleElements = [seFont, seBorder]
          OnClick = ButtonRecipientsClick
        end
      end
      object GroupBoxProducts: TGroupBox
        Left = 13
        Top = 159
        Width = 215
        Height = 170
        Caption = #1059#1087#1088#1072#1074#1083#1110#1085#1085#1103' '#1087#1088#1086#1076#1091#1082#1090#1072#1084#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object ButtonGroups: TButton
          Left = 17
          Top = 32
          Width = 178
          Height = 25
          Caption = #1043#1088#1091#1087#1080' '#1090#1086#1074#1072#1088#1110#1074
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          StyleElements = [seFont, seBorder]
          OnClick = ButtonGroupsClick
        end
        object ButtonProducts: TButton
          Left = 17
          Top = 63
          Width = 178
          Height = 25
          Caption = #1058#1086#1074#1072#1088#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          StyleElements = [seFont, seBorder]
          OnClick = ButtonProductsClick
        end
        object ButtonOffices: TButton
          Left = 17
          Top = 94
          Width = 178
          Height = 25
          Caption = #1054#1092#1110#1089#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          StyleElements = [seFont, seBorder]
          OnClick = ButtonOfficesClick
        end
        object ButtonWarehouses: TButton
          Left = 17
          Top = 125
          Width = 178
          Height = 25
          Caption = #1057#1082#1083#1072#1076#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          StyleElements = [seFont, seBorder]
          OnClick = ButtonWarehousesClick
        end
      end
      object GroupBoxReports: TGroupBox
        Left = 13
        Top = 335
        Width = 215
        Height = 79
        Caption = #1047#1074#1110#1090#1085#1110#1089#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        object ButtonReport: TButton
          Left = 17
          Top = 32
          Width = 178
          Height = 25
          Caption = #1047#1074#1110#1090#1085#1110#1089#1090#1100' '#1091' Excel'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          StyleElements = [seFont, seBorder]
          OnClick = ButtonReportClick
        end
      end
    end
  end
  object ButtonExit: TButton
    Left = 934
    Top = 35
    Width = 153
    Height = 25
    Caption = #1042#1080#1081#1090#1080' '#1079' '#1089#1080#1089#1090#1077#1084#1080
    TabOrder = 1
    OnClick = ButtonExitClick
  end
  object ButtonFAQ: TButton
    Left = 853
    Top = 35
    Width = 75
    Height = 25
    Caption = 'FAQ'
    TabOrder = 2
    OnClick = ButtonFAQClick
  end
end
