
dat=read.csv("~/Documents/github/dataStructure/hw3/memoryComp.csv")

dat$Type <- as.numeric(dat$Type)
ntype <- max(dat$Type)            # calculating the number of levels of the variable
xrange <- range(dat$Number)           # calculating the range of the variable age                         
yrange <- range(dat$Memory) # calculating the range of the variable circumference
plot(xrange, yrange,                  # set up plot                           
     type="n",                        # type = n oduce is used to set up the axes for later commands                    
     xlab="Snapshot Number",
     ylab="Memory(B)"
 )                                                         
colors <- rainbow(ntype)             # colors are equal to the number of the level of the variable Tree                               
linetype <- c(1:ntype)  
linetype                                 
plotchar <- seq(18, 18+ntype, 1)     # we use this variable to define symbol for plotting  points with pch that here are: 18 19 20 21 22 23                    
for (i in 1:ntype) {                 # add lines                     
    Type <- subset(dat, Type==i)                       
    lines(Type $Number, Type $Memory,
          type="b",                                       
          lwd=2,                                          
          lty=linetype[i],            # changes the default symbol points type: see the figure at the end of the article                  
          col=colors[i],              # changes the default line type: see the figure at the end of the article                               
          pch=plotchar[i]                                 
    )                                                     
}                                                      
title("Memory Requirement Comparison")   # add legend
legend(xrange[1], yrange[2],                              
       c("Linked List", "Dynamic Array"),
       cex=0.8,                                # cex: specifies the symbol size. cex is a number indicating                                   
       col=colors,                             # the amount by which plotting symbols should be scaled relative to the default. 
       pch=plotchar,                           # 1=default, 1.5 is 50% larger, 0.5 is 50% smaller                          
       lty=linetype,
)
rm(list=ls())
