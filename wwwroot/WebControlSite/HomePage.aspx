<%@ Page MasterPageFile="~/myMaster.master" Inherits="WebControl.HomePage" Title="Home Page" %>

<asp:Content ID="Content2" ContentPlaceHolderID="body" Runat="Server">
    <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/DomainPage.aspx">
        To Domain Page
    </asp:HyperLink>
</asp:Content>

