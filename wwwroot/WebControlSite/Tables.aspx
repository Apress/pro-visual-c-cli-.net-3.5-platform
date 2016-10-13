<%@ Page Inherits="WebControl.Tables" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
                      "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
                      
<html xmlns="http://www.w3.org/1999/xhtml">
    <head id="Head1" runat="server">
        <title id="PageTitle" runat="server">Nobody is happy right now</title>
    </head>
    <body>
        <form id="form1" runat="server">
        <div>
            <asp:Table ID="FilesTable" runat="server" GridLines="Both">
                <asp:TableRow>
                    <asp:TableCell Text="Name"></asp:TableCell>
                    <asp:TableCell Text="Created"></asp:TableCell>
                    <asp:TableCell Text="Length"></asp:TableCell>
                    <asp:TableCell Text="Attributes"></asp:TableCell>
                    <asp:TableCell Style="font-size: XX-small" Text="Make Happy">
                    </asp:TableCell>
                </asp:TableRow>
            </asp:Table>
        </div>
        </form>
    </body>
</html>
