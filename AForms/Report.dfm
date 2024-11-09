object FormReport: TFormReport
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1047#1074#1110#1090#1085#1110#1089#1090#1100
  ClientHeight = 504
  ClientWidth = 537
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnShow = FormShow
  TextHeight = 15
  object PageControl: TPageControl
    Left = 12
    Top = 11
    Width = 513
    Height = 481
    ActivePage = TabSheetOrders
    TabOrder = 0
    OnChange = PageControlChange
    object TabSheetOrders: TTabSheet
      Caption = #1047#1072#1084#1086#1074#1083#1077#1085#1085#1103
      object GroupBoxFitersOR: TGroupBox
        Left = 22
        Top = 14
        Width = 460
        Height = 371
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
          Top = 53
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
          Top = 53
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
          Top = 109
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
          Top = 109
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
        object DateTimePicker_2OR: TDateTimePicker
          Left = 191
          Top = 49
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
        object DateTimePicker_1OR: TDateTimePicker
          Left = 109
          Top = 49
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
        object DateTimePicker_4OR: TDateTimePicker
          Left = 191
          Top = 105
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
        object DateTimePicker_3OR: TDateTimePicker
          Left = 109
          Top = 105
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
          Left = 233
          Top = 312
          Width = 208
          Height = 43
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
          ItemIndex = 0
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
        object GroupBoxChoiceProductOR: TGroupBox
          Left = 15
          Top = 150
          Width = 202
          Height = 203
          Caption = #1058#1086#1074#1072#1088
          TabOrder = 7
          object LabelChoiceProductGroupOR: TLabel
            Left = 17
            Top = 28
            Width = 72
            Height = 15
            Caption = #1043#1088#1091#1087#1072' '#1090#1086#1074#1072#1088#1091
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object LabelChoiceProductOR: TLabel
            Left = 17
            Top = 84
            Width = 32
            Height = 15
            Caption = #1058#1086#1074#1072#1088
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object LabelChoiceProductFilterOR: TLabel
            Left = 17
            Top = 140
            Width = 37
            Height = 15
            Caption = #1060#1110#1083#1100#1090#1088
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object ComboBoxChoiceProductGroupOR: TComboBox
            Left = 17
            Top = 49
            Width = 168
            Height = 23
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnChange = ComboBoxChoiceProductGroupORChange
          end
          object ComboBoxChoiceProductOR: TComboBox
            Left = 17
            Top = 105
            Width = 168
            Height = 23
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
          object ComboBoxChoiceProductFilterOR: TComboBox
            Left = 17
            Top = 161
            Width = 168
            Height = 23
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 2
            Text = #1055#1088#1080#1089#1091#1090#1085#1110#1081
            Items.Strings = (
              #1055#1088#1080#1089#1091#1090#1085#1110#1081
              #1042#1110#1076#1089#1091#1090#1085#1110#1081)
          end
        end
        object GroupBoxChoiceUsersOR: TGroupBox
          Left = 233
          Top = 150
          Width = 208
          Height = 147
          Caption = #1050#1086#1088#1080#1089#1090#1091#1074#1072#1095#1110
          TabOrder = 8
          object LabelChoiceCustomerOR: TLabel
            Left = 17
            Top = 28
            Width = 55
            Height = 15
            Caption = #1047#1072#1084#1086#1074#1085#1080#1082
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object LabelChoiceRecipientOR: TLabel
            Left = 17
            Top = 84
            Width = 62
            Height = 15
            Caption = #1054#1090#1088#1080#1084#1091#1074#1072#1095
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object ComboBoxChoiceCustomerOR: TComboBox
            Left = 17
            Top = 49
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
          object ComboBoxChoiceRecipientOR: TComboBox
            Left = 17
            Top = 105
            Width = 168
            Height = 23
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
          end
        end
      end
      object ButtonSaveOR: TButton
        Left = 22
        Top = 397
        Width = 460
        Height = 42
        Caption = #1054#1090#1088#1080#1084#1072#1090#1080' '#1079#1074#1110#1090' '#1087#1086' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103#1084
        TabOrder = 1
        OnClick = ButtonSaveORClick
      end
    end
    object TabSheetCalls: TTabSheet
      Caption = #1044#1079#1074#1110#1085#1082#1080
      ImageIndex = 1
      object ButtonSaveC: TButton
        Left = 22
        Top = 397
        Width = 460
        Height = 42
        Caption = #1054#1090#1088#1080#1084#1072#1090#1080' '#1079#1074#1110#1090' '#1087#1086' '#1076#1079#1074#1110#1085#1082#1072#1084
        TabOrder = 0
        OnClick = ButtonSaveCClick
      end
      object GroupBoxFitersC: TGroupBox
        Left = 22
        Top = 14
        Width = 460
        Height = 371
        Caption = #1060#1110#1083#1100#1090#1088#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object LabelСallStateO: TLabel
          Left = 273
          Top = 84
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
        object LabelChoiceTime_1C: TLabel
          Left = 15
          Top = 53
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
        object LabelChoiceTime_2C: TLabel
          Left = 172
          Top = 53
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
        object LabelChoiceDate_2C: TLabel
          Left = 172
          Top = 109
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
        object LabelChoiceDate_1C: TLabel
          Left = 15
          Top = 109
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
        object LabelChoiceOfficeC: TLabel
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
        object GroupBoxChoiceEmplC: TGroupBox
          Left = 15
          Top = 150
          Width = 202
          Height = 203
          Caption = #1057#1087#1110#1074#1088#1086#1073#1110#1090#1085#1080#1082
          TabOrder = 0
          object LabelChoiceEmplFilterC: TLabel
            Left = 17
            Top = 140
            Width = 37
            Height = 15
            Caption = #1060#1110#1083#1100#1090#1088
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object LabelChoiceEmplRoleC: TLabel
            Left = 17
            Top = 28
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
          object LabelChoiceEmplC: TLabel
            Left = 17
            Top = 84
            Width = 73
            Height = 15
            Caption = #1057#1087#1110#1074#1088#1086#1073#1110#1090#1085#1080#1082
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
          end
          object ComboBoxChoiceEmplFilterC: TComboBox
            Left = 17
            Top = 161
            Width = 168
            Height = 23
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ItemIndex = 0
            ParentFont = False
            TabOrder = 0
            Text = #1055#1088#1080#1089#1091#1090#1085#1110#1081
            Items.Strings = (
              #1055#1088#1080#1089#1091#1090#1085#1110#1081
              #1042#1110#1076#1089#1091#1090#1085#1110#1081)
          end
          object ComboBoxChoiceEmplRoleC: TComboBox
            Left = 17
            Top = 49
            Width = 168
            Height = 23
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -12
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            OnChange = ComboBoxChoiceEmplRoleCChange
          end
          object ComboBoxChoiceEmplC: TComboBox
            Left = 17
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
          end
        end
        object ComboBoxCallStateC: TComboBox
          Left = 273
          Top = 105
          Width = 168
          Height = 23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ItemIndex = 0
          ParentFont = False
          TabOrder = 1
          Text = #1059#1089#1110
          Items.Strings = (
            #1059#1089#1110
            #1053#1086#1074#1080#1081
            #1042' '#1088#1086#1073#1086#1090#1110
            #1047#1072#1082#1088#1080#1090#1080#1081)
        end
        object DateTimePicker_1C: TDateTimePicker
          Left = 109
          Top = 49
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
          TabOrder = 2
        end
        object DateTimePicker_2C: TDateTimePicker
          Left = 191
          Top = 49
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
          TabOrder = 3
        end
        object DateTimePicker_4C: TDateTimePicker
          Left = 191
          Top = 105
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
        object DateTimePicker_3C: TDateTimePicker
          Left = 109
          Top = 105
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
          TabOrder = 5
        end
        object ComboBoxChoiceOfficeC: TComboBox
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
          TabOrder = 6
        end
        object ButtonClearC: TButton
          Left = 233
          Top = 312
          Width = 208
          Height = 43
          Caption = #1054#1095#1080#1089#1090#1080#1090#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          TabOrder = 7
          StyleElements = [seFont, seBorder]
          OnClick = ButtonClearClick
        end
      end
    end
  end
  object SaveDialog: TSaveDialog
    Left = 164
    Top = 10
  end
end
