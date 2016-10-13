<%@ Page Inherits="WebControl.Blank1" %>

<%@ Register src="myPageHeader.ascx" tagname="myPageHeader" tagprefix="uc1" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>Blank1</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <uc1:myPageHeader ID="myPageHeader1" runat="server" Level="Home" />
    
    </div>
    </form>
</body>
</html>

