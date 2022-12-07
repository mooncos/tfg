function fig = figure_export(fig, filename, width_in, height_in)
    arguments
        fig matlab.ui.Figure = matlab.ui.Figure.empty;
        filename string = "figure.pdf";
        width_in(1,1) double {mustBeFinite} = 5.9055;
        height_in(1,1) double {mustBeFinite} = 3.6498;
    end
    
    

end