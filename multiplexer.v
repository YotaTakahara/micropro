`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/29 09:44:00
// Design Name: 
// Module Name: decoder
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
`include "define.vh"

module multiplexer(clk,reg_we,
 rs1_data,rs2_data,aluop1_type,aluop2_type,imm,op1,op2,pc);
 
   input clk;
   input wire[31:0] imm;
//   input wire [5:0] alucode;
   input wire[1:0] aluop1_type;
   input wire [1:0] aluop2_type;
   input wire reg_we;
   input [31:0]rs1_data;
   input  [31:0]rs2_data;
   input [31:0]pc;


   output reg [31:0] op1;
   output reg [31:0] op2;


always @(*)begin
    case(aluop1_type)
    `OP_TYPE_REG:op1=rs1_data;
   `OP_TYPE_IMM:op1=imm;
    `OP_TYPE_NONE:op1=32'd0;
    default:op1=32'd0;
    endcase
    case(aluop2_type)
    `OP_TYPE_REG:op2=rs2_data;
    `OP_TYPE_IMM:op2=imm;
    `OP_TYPE_PC:op2=pc;
    `OP_TYPE_NONE:op2 =32'd0;
    default:op2=32'd0;
endcase
  
end
endmodule

