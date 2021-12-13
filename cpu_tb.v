`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/07 13:17:19
// Design Name: 
// Module Name: cpu_tb
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

module cpu_tb;
    reg sysclk;
    reg cpu_resetn;
  

    parameter CYCLE = 1000;

    always #(CYCLE/2) sysclk = ~sysclk;

    top cpu0(
       .sysclk(sysclk),
       .cpu_resetn(~cpu_resetn)
   //    .uart_tx(uart_tx)
    );

    initial begin
        #10     sysclk     = 1'd0;
                cpu_resetn    = 1'd0;
        #(CYCLE) cpu_resetn = 1'd1;
        #(10000000) $finish;
    end
endmodule
