object DataBase: TDataBase
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 480
  Width = 640
  object ADOConnection: TADOConnection
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Extended Properti' +
      'es="DSN=Delivery;SERVER=localhost;UID=root;DATABASE=delivery;POR' +
      'T=3306;CHARSET=utf8mb4;SSLMODE=DISABLED"'
    LoginPrompt = False
    Provider = 'MSDASQL.1'
    Left = 48
    Top = 32
  end
  object ADOQuery: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    Left = 152
    Top = 32
  end
end
