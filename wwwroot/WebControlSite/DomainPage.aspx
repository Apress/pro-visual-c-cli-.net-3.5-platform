<%@ Page MasterPageFile="~/myMaster.master" Inherits="WebControl.DomainPage" Title="Domain Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="body" Runat="Server">
    <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/HomePage.aspx">
        To Home Page
    </asp:HyperLink>
</asp:Content>

