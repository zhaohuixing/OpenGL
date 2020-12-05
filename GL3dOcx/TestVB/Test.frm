VERSION 5.00
Object = "{A015E01F-7691-11D3-955D-8422F5C00000}#1.0#0"; "GL3DOCX.OCX"
Begin VB.Form Test 
   AutoRedraw      =   -1  'True
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Test 3DFont OCX"
   ClientHeight    =   4035
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4785
   ClipControls    =   0   'False
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4035
   ScaleWidth      =   4785
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   3360
      TabIndex        =   4
      Top             =   3480
      Width           =   1095
   End
   Begin GL3DOCXLib.GL3dOcx GL3dOcx1 
      Height          =   3135
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   4575
      _Version        =   65536
      _ExtentX        =   8070
      _ExtentY        =   5530
      _StockProps     =   0
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   960
      TabIndex        =   1
      Top             =   3480
      Width           =   1095
   End
   Begin VB.Label Content 
      Caption         =   "Content:  (Method) "
      Height          =   495
      Index           =   2
      Left            =   2520
      TabIndex        =   3
      Top             =   3480
      Width           =   735
   End
   Begin VB.Label Content 
      Caption         =   "Content:  (Property) "
      Height          =   495
      Index           =   0
      Left            =   120
      TabIndex        =   2
      Top             =   3480
      Width           =   735
   End
End
Attribute VB_Name = "Test"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Form_Load()
   Text1.Text = GL3dOcx1.Content
   Text2.Text = GL3dOcx1.Content
End Sub

Private Sub Form_Paint()
   GL3dOcx1_GLDraw
End Sub

Private Sub GL3dOcx1_GLDraw()
   GL3dOcx1.GLRender
End Sub


Private Sub Text1_KeyUp(KeyCode As Integer, Shift As Integer)
   If KeyCode = vbKeyReturn Then
      GL3dOcx1.Content = Text1.Text
      Text2.Text = Text1.Text
      GL3dOcx1_GLDraw
   End If
End Sub

Private Sub Text1_LostFocus()
   GL3dOcx1.Content = Text1.Text
   Text2.Text = Text1.Text
   GL3dOcx1_GLDraw
End Sub


Private Sub Text2_KeyUp(KeyCode As Integer, Shift As Integer)
   If KeyCode = vbKeyReturn Then
      GL3dOcx1.Content = Text2.Text
      Text1.Text = Text2.Text
      GL3dOcx1_GLDraw
   End If
End Sub

Private Sub Text2_LostFocus()
   GL3dOcx1.Content = Text2.Text
   Text1.Text = Text2.Text
   GL3dOcx1_GLDraw
End Sub
