<%@ Page Inherits="WebControl.ChangeColor" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
                      "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
    <head id="Head1" runat="server">
        <title>Change Color</title>
    </head>
    <body>
        <form id="form1" runat="server">
        <div>
            <asp:TextBox ID="tbChanger" runat="server" AutoPostBack="True" 
                         ontextchanged="tbChanger_TextChanged"></asp:TextBox>
        </div>
        </form>
    </body>
</html>

