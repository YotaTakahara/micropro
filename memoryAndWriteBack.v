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

module memoryAndWriteBack(reg_we,is_load,is_store,is_halt,dstreg_num,op1,op2,alu_result,srcreg2_num);


input reg_we,is_load,is_store,is_halt;
input [31:0]op1,op2,alu_result;
input [4:0]dstreg_num;

output reg [31:0]r_data;

wire [31:0] r_data_tmp;
wire [31:0] w_data_tmp;

// data_mem data_mem1(clk,is_store,dstreg_num,alu_result[4:0],r_data_tmp,32'd0);
// reg_file reg_file1(clk,reg_we,srcreg2_num,0,w_data_tmp,0);
//  data_mem1(clk,is_store,dstreg_num,alu_result[4:0],0,w_data_tmp);

always @(*)begin
    if(is_load)begin
      r_data<=r_data_tmp;
    end else if(is_store) begin
      r_data<=32'd0;
    end
  
end
//reg_file1(clk,reg_we,0,srcreg2_num,0,r_data);



endmodule


