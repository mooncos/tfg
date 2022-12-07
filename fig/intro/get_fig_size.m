function [fig_width_in, fig_height_in] = get_fig_size(width, fraction)
    arguments
        width(1,1) double {mustBeFinite} = 426.79141;
        fraction(1,1) double {mustBeFinite} = 1;
    end
    
    fig_width_pt = width * fraction;

    % Convert from pt to inches
    inches_per_pt = 1 / 72.27;

    % Golden ratio to set aesthetic figure height
    % https://disq.us/p/2940ij3
    golden_ratio = (5^0.5 - 1) / 2;

    % Figure width in inches
    fig_width_in = fig_width_pt * inches_per_pt;
    % Figure height in inches
    fig_height_in = fig_width_in * golden_ratio;    
end