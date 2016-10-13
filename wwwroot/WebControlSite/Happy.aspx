<%@ Page Inherits="WebControl.Happy" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
                      "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
    <head id="Head1" runat="server">
        <title>Happy Face</title>
    </head>
    <body>
        <form id="Happy" runat="server">
        <div>
            <asp:Image ID="imgHappy" runat="server" ImageUrl="~/Images/Happy.GIF" />
        </div>
        </form>
    </body>
</html>
<script type="text/javascript" language="JavaScript">
    Happy.submit();
</script>

