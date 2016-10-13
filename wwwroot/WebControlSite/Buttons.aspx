<%@ Page Inherits="WebControl.Buttons" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
                      "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>Buttons</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table cellspacing="4" cellpadding="4" border="2">
            <tr>
                <td>
                    <asp:RadioButton ID="rbColorful" runat="server" 
                                     AutoPostBack="True" Text="Colorful" 
                                     GroupName="PageGroup" 
                                     OnCheckedChanged="RB_CheckedChanged">
                    </asp:RadioButton>
                    <p />
                    <asp:RadioButton ID="rbHappy" runat="server" 
                                     AutoPostBack="True" Text="Happy Face" 
                                     GroupName="PageGroup" 
                                     OnCheckedChanged="RB_CheckedChanged">
                    </asp:RadioButton>
                    <p />
                    <asp:RadioButton ID="rbChange" runat="server" 
                                     AutoPostBack="True" Text="TextBox Color" 
                                     GroupName="PageGroup" 
                                     OnCheckedChanged="RB_CheckedChanged">
                    </asp:RadioButton>
                </td>
                <td>
                    <asp:CheckBox ID="cbColorful" runat="server" 
                                  Text="Colorful">
                    </asp:CheckBox>
                    <p />
                    <asp:CheckBox ID="cbHappy" runat="server" 
                                  Text="Happy Face">
                    </asp:CheckBox>
                    <p />
                    <asp:CheckBox ID="cbChange" runat="server" 
                                  Text="TextBox Color">
                    </asp:CheckBox>
                    <p />
                    <asp:Button ID="bnCheckBoxes" runat="server" 
                                Text="Go to first checked box" 
                                OnClick="bnCheckBoxes_Click">
                    </asp:Button>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Button ID="bnColorful" runat="server" Text="Colorful" 
                               ForeColor="Navy" BorderColor="Purple" 
                               BackColor="PaleGreen" 
                               OnClick="bnColorful_Click">
                    </asp:Button>
                    <p />
                    <asp:ImageButton ID="ibnHappy" runat="server" 
                                     BorderStyle="Outset" 
                                     ImageUrl="images/Happy.GIF" 
                                     Style="width: 32px"
                                     OnClick="ibnHappy_Click" >
                    </asp:ImageButton>
                    <p />
                    <asp:Button ID="bnChange" runat="server" 
                                Text="TextBox Color" 
                                OnClick="bnChange_Click">
                    </asp:Button>
                </td>
                <td>
                    <asp:HyperLink ID="hlColorful" runat="server" 
                                   NavigateUrl="Colorful.aspx">
                        Colorful
                    </asp:HyperLink>
                    <p />
                    <asp:HyperLink ID="hlHappy" runat="server" 
                                   NavigateUrl="Happy.aspx" 
                                   ImageUrl="images/Happy.GIF">
                        Happy Face
                    </asp:HyperLink>
                    <p />
                    <asp:LinkButton ID="lbnChange" runat="server" 
                                    OnClick="lbnChange_Click">
                        TextBox Color
                    </asp:LinkButton>
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
